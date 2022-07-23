#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#define WIDTH 700
#define HEIGHT 500

SDL_Window *window;
SDL_Renderer *render;
SDL_Texture *texture;
SDL_Rect ds;
SDL_Rect st;

void Erro(){

    FILE *m=fopen("error.txt","a");
    fprintf(m,"Sorry bro:\t\n%s",SDL_GetError());
    fclose(m);
    exit(1);

}

SDL_Texture * LoadTexture(FILE *m){
    SDL_Texture *newTexture;
    SDL_Surface *newjpg=IMG_Load(m);
    if(newjpg==NULL)    Erro();
    SDL_SetColorKey(newjpg,SDL_TRUE,SDL_MapRGB(newjpg->format,0,0xFF,0xFF));

    newTexture=SDL_CreateTextureFromSurface(render,newjpg);
    SDL_FreeSurface(newjpg);
    newjpg=NULL;
    return newTexture;
}
void Close()
{
SDL_DestroyTexture(texture);
SDL_DestroyRenderer(render);
SDL_DestroyWindow(window);
window=NULL;
render=NULL;
texture=NULL;
SDL_Quit();


}
