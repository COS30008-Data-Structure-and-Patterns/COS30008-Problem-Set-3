#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "../include/Dungeon.h"
#include "../include/Player.h"
#include "../include/AttackVisitor.h"
#include "../include/PickupVisitor.h"
#include "../include/InspectVisitor.h"

void printFrame(const string & title) {
    cout << "========================================\n";
    cout << title << "\n";
    cout << "========================================\n";
}

// Main game loop
void gameLoop(DungeonNode * root) {
    Player player("Kiddy", 30, 5);
    DungeonNode * current = root;

    printFrame("Welcome to the Text Dungeon");
    cout << "Commands: move, attack, pickup, inspect, inv, help, quit\n" << endl;

    cout << player << endl;

    while ( true ) {
        if ( !player.isAlive() ) {
            cout << "You have died. Game over.\n";
            break;
        }

        cout << "\n";
        cout << "Location: " << current->getKey().name << endl;
        current->getKey().displayContents();

        vector<int> children;
        for ( int i = 0; i < 4; i++ ) {
            try {
                DungeonNode & child = (*current)[i];
                if ( !child.isEmpty() ) {
                    children.push_back(i);
                }
            } catch ( ... ) {}
        }

        cout << "Doors: ";
        if ( children.empty() ) cout << "(none)";
        else for ( int idx : children ) cout << "[" << idx << "] ";
        cout << "\n\n";

        cout << "Enter command: ";
        string cmd;
        cin >> cmd;

        // ======================
        // HELP
        // ======================
        if ( cmd == "help" ) {
            cout << "Commands:" << endl;
            cout << "  move <door>\n";
            cout << "  attack <monster index>" << endl;
            cout << "  pickup <item index>" << endl;
            cout << "  inspect m <i> / inspect i <i>" << endl;
            cout << "  inv" << endl;
            cout << "  quit" << endl;
            continue;
        }

        // ======================
        // QUIT
        // ======================
        if ( cmd == "quit" ) {
            cout << "Exiting game..." << endl;
            break;
        }

        // ======================
        // SHOW INVENTORY
        // ======================
        if ( cmd == "inv" ) {
            player.displayInventory();
            continue;
        }

        // ======================
        // MOVE
        // ======================
        if ( cmd == "move" ) {
            int idx;
            if ( !(cin >> idx) ) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter door index." << endl;
                continue;
            }

            try {
                DungeonNode & child = (*current)[idx];

                if ( child.isEmpty() ) {
                    cout << "There is no door there.\n";
                } else {
                    current = &child;
                    cout << "You move into: " << current->getKey().name << endl;
                }
            } catch ( ... ) {
                cout << "Invalid door index.\n";
            }
            continue;
        }

        // ======================
        // ATTACK
        // ======================
        if ( cmd == "attack" ) {
            int midx;
            if ( !(cin >> midx) ) {
                cout << "Provide monster index to attack." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if ( midx < 0 || midx >= (int) current->getKey().monsters.size() ) {
                cout << "Invalid monster index." << endl;
                continue;
            }

            Monster & m = current->getKey().monsters[midx];
            AttackVisitor av(player.getAttackPower());

            m.accept(av);

            if ( m.isAlive() ) {
                cout << m.name << " counterattacks for "
                    << m.attackPower << " damage!" << endl;
                player.setHP(player.getHP() - m.attackPower);
                cout << "Your HP: " << player.getHP() << "/" << player.getMaxHP() << endl;
                cout << player.ShowPlayerHP() << endl;
            } else {
                current->getKey().monsters.erase(
                    current->getKey().monsters.begin() + midx
                );
            }

            continue;
        }

        // ======================
        // PICKUP
        // ======================
        if ( cmd == "pickup" ) {
            int iidx;
            if ( !(cin >> iidx) ) {
                cout << "Provide item index." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if ( iidx < 0 || iidx >= current->getKey().items.getSize() ) {
                cout << "Invalid item index.\n";
                continue;
            }

            Item it = current->getKey().items[iidx];

            PickupVisitor pv(&player.inventory);
            it.accept(pv);

            current->getKey().items.removeAt(iidx);

            continue;
        }

        // ======================
        // INSPECT
        // ======================
        if ( cmd == "inspect" ) {
            char type;
            cin >> type;

            InspectVisitor iv;

            if ( type == 'm' ) {
                int midx;
                cin >> midx;

                if ( midx < 0 || midx >= (int) current->getKey().monsters.size() ) {
                    cout << "Invalid monster index.\n";
                    continue;
                }

                Monster & m = current->getKey().monsters[midx];
                m.accept(iv);
            } else if ( type == 'i' ) {
                int iidx;
                cin >> iidx;

                if ( iidx < 0 || iidx >= current->getKey().items.getSize() ) {
                    cout << "Invalid item index.\n";
                    continue;
                }

                Item it = current->getKey().items[iidx];
                it.accept(iv);
            } else {
                cout << "Usage: inspect m <idx>  OR  inspect i <idx>\n";
            }
            continue;
        }

        // ======================
        // UNKNOWN COMMAND
        // ======================
        cout << "Unknown command. Type 'help' for list.\n";
    }
}

// ======================
// MAIN FUNCTION
// ======================

int main() {
    Dungeon dungeon;
    DungeonNode * root = dungeon.buildSampleDungeon();

    gameLoop(root);

    return 0;
}
