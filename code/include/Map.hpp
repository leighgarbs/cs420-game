#if !defined MAP_HPP
#define MAP_HPP

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class Map
{
public:
    
    Map();
    
    ~Map();
    
    virtual bool initialize();
    
    bool createMap(std::string filename);
    
    int* getMap();
    
    int getTerrain(int x, int y) const;

    void drawMap(sf::RenderWindow *App);

    int get_map_row_size();

    int get_map_col_size();
        
private:    

    const int map_rows = 6;
   
    const int map_cols = 8;
    
    int map_array[6][8];

    // W = 0, L = 1
    enum Terrain {W=0, L=1};
};

inline int* Map::getMap()
{
    return *map_array;
}

inline int Map::getTerrain(int x, int y) const
{
    return map_array[x][y];
}

inline int Map::get_map_row_size()
{
    return map_rows;
}

inline int Map::get_map_col_size()
{
    return map_cols;
}

#endif

