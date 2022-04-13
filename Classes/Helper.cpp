//
// Created by asus on 13/04/2022.
//

#include "Helper.h"


/*
vector<GameObject> Game::readMap(std::string map_name) {
    string myText;
    cout << endl << "Reading map from " << map_name << endl;
    vector<GameObject> gameObjects;
    int n_lines = 0, n_columns = 0;
    // Reads the map from the text file according to its id.
    ifstream MyReadFile(map_name);
    int first_line = 0;
    if (MyReadFile.is_open()) {
        int dimension = 0;
        string line;
        while (getline(MyReadFile, line)) {
            if (first_line == 0) {
                // Se for a primeira linha do file vou ler as dimens�es e marcar que a primeira linha j� foi lida.
                for (int letter = 0; letter < line.length(); letter++) {
                    if (!dimension) {
                        if (line[letter] != 'x' && line[letter] != ' ') {
                            n_lines = n_lines * 10;
                            n_lines += (static_cast<int>(line[letter]) - 48);
                        }
                        else if (line[letter] != ' ')
                        {
                            dimension++;
                        }
                    }
                    else {
                        if (line[letter] != ' ') {
                            n_columns = n_columns * 10;
                            n_columns += (static_cast<int>(line[letter]) - 48);
                        }
                    }
                }
                first_line++;
                dimension = 0;
            }
            else {
                if (line.length() < n_columns) {
                    cout << "ERROR: Map file's columns number does not correspond." << endl;
                    return {};
                }
                //cout << line <<  endl;
                for (int letter = 0; letter < n_columns; letter++) {
                    switch(line[letter]){
                        case 82: gameObjects.push_back(GameObject(2, Position({letter, dimension})));
                            break;
                        case 114: gameObjects.push_back(GameObject(3, Position({letter, dimension})));
                            break;
                        case 72: gameObjects.push_back(GameObject(0, Position({letter, dimension})));
                            break;
                        case 104: gameObjects.push_back(GameObject(1, Position({letter, dimension})));
                            break;
                        case 42: gameObjects.push_back(GameObject(4, Position({letter, dimension})));
                            break;
                        case 43: gameObjects.push_back(GameObject(5, Position({letter, dimension})));
                            break;
                        case 79: gameObjects.push_back(GameObject(6, Position({letter, dimension})));
                            break;
                        default:
                            break;
                    }
                }
                dimension++;
            }
        }
    }
    maze.setMaze(n_lines, n_columns);
    // Close the MyReadFile
    MyReadFile.close();
    return gameObjects;
};
 */