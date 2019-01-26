#ifndef MAP_DEF_
#define MAP_DEF_

#include "main.h"

class Map {

    public:
        Map(){}
        ~Map(){}

        void Init();

        void Update(int size, bool bway);

        void Render(SDL_Renderer *renderer, Uint32 score);

        int size_of_wall = 128;

        int start_wall_break = -480, finish_wall_break = -480;

        bool broadway = 1;

    private:

        SDL_Texture *ground = NULL;
        //int map[20][30];
};

#endif //MAP_DEF_
