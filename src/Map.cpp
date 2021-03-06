#include "Map.h"

void Map::Init() {

}

void Map::Update(int start_break, bool bway) {

    start_wall_break = start_break;
    finish_wall_break = start_break + 128;

    broadway = bway;

    if (broadway == 1) {
        size_of_wall = 128;
    } else {
        size_of_wall = 256;
    }
}

void Map::Render(SDL_Renderer *renderer, Uint32 score) {

    //Change Color
    SDL_SetRenderDrawColor(renderer, 40, 111, 15, SDL_ALPHA_OPAQUE);

    //Make Lines
    for (int i = 0; i < 480; ++i) {
        //cout << score << ' ' << start_wall_break << ' ' << i << ' ' << i - (int)score + start_wall_break <<  ' ' << finish_wall_break << '\n';
        if (!broadway) {
            if ((int)score - i > finish_wall_break) {
                SDL_RenderDrawLine(renderer, 0, i, (size_of_wall), i);
                SDL_RenderDrawLine(renderer, 640 - (size_of_wall), i, 640, i);
                //cout<<"1"<<i<<endl;
            }
            else if ((int)score - i > start_wall_break) {
                //cout << ".\n";
                SDL_RenderDrawLine(renderer, 0, i, (size_of_wall - 128 + (int)score - i - start_wall_break), i);
                SDL_RenderDrawLine(renderer, 640 - (size_of_wall - 128 + (int)score - i - start_wall_break), i, 640, i);
                //cout<<"T::"<<i<<endl;
            }
            else {
                SDL_RenderDrawLine(renderer, 0, i, (size_of_wall - 128), i);
                SDL_RenderDrawLine(renderer, 640 - (size_of_wall - 128), i, 640, i);
                //cout<<"3"<<i<<endl;
            }
        }
        else {
            if ((int)score - i > finish_wall_break) {
                SDL_RenderDrawLine(renderer, 0, i, (size_of_wall), i);
                SDL_RenderDrawLine(renderer, 640 - (size_of_wall), i, 640, i);
                //cout<<"1::"<<i<<endl;
            }
            else if ((int)score - i > start_wall_break) {
                //cout << ".\n";
                SDL_RenderDrawLine(renderer, 0, i, (size_of_wall + 128 - (int)score + i + start_wall_break), i);
                SDL_RenderDrawLine(renderer, 640 - (size_of_wall + 128 - (int)score + i + start_wall_break), i, 640, i);
                //cout<<"2::"<<i<<endl;
            }
            else {
                SDL_RenderDrawLine(renderer, 0, i, (size_of_wall + 128), i);
                SDL_RenderDrawLine(renderer, 640 - (size_of_wall + 128), i, 640, i);
                //cout<<"N::"<<i<<endl;
            }
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 0, 280, 640, 280);

    SDL_SetRenderDrawColor(renderer, 109, 109, 111, SDL_ALPHA_OPAQUE);
    for (int i = 281; i < 480; ++i) {
        SDL_RenderDrawLine(renderer, 0, i, 640, i);
    }
}
