
#include "help.h"


SDL_Texture *backgroundtexture;
SDL_Rect react[4];

int Init(){
    if(SDL_Init(SDL_INIT_VIDEO)<0)      Erro();

    window=SDL_CreateWindow("14 lesson",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    if(window==NULL)        Erro();
    render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(render==NULL)        Erro();
    SDL_SetRenderDrawColor(render,0x41,0x69,0xE1,0xAA);
    SDL_RenderClear(render);

    int pngFlag=IMG_INIT_PNG;
    if(!IMG_Init(pngFlag)&pngFlag)      printf("LOL");

    texture=LoadTexture("foo.png");
    if(texture==NULL)  Erro();


}




int main(int argc, char *argv[]){
     int SCREEN_FPS=30;
     int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

    int countFrames;
    float fps;
    Init();
SDL_Rect frame[4];
frame[0].x=0;
frame[0].y=0;
frame[0].w=64;
frame[0].h=205;

frame[1].x=64;
frame[1].y=0;
frame[1].w=64;
frame[1].h=205;

frame[2].x=128;
frame[2].y=0;
frame[2].w=64;
frame[2].h=205;

frame[3].x=192;
frame[3].y=0;
frame[3].w=64;
frame[3].h=205;
SDL_Rect pos={WIDTH-frame->w,0,64,205};
int i=0;
    //SDL_RenderCopy(render,texture,&frame[i],NULL);
    //SDL_RenderPresent(render);

    SDL_Event event;
    int quit=0;

    while(!quit){
        SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
        Uint32 start=SDL_GetTicks();
        fps=countFrames/(SDL_GetTicks()/1000.f);
        if(fps>2000000) fps=0;
        system("cls");
        printf("%Passed FPS %0.2f\n",fps);
        while( SDL_PollEvent(&event)!=0)
        {
            if(event.type==SDL_QUIT)       quit=1;
            if(event.type==SDL_KEYDOWN)
                switch(event.key.keysym.sym)
                {
                case 'w':
                    if(SCREEN_FPS>=95)  SCREEN_FPS=100;
                    else    SCREEN_FPS+=10;
                    break;
                case 's':
                    if(SCREEN_FPS<15)   SCREEN_FPS=1;
                    else    SCREEN_FPS-=10;
                    break;
                }


        }
        SDL_RenderClear(render);
        SDL_RenderCopy(render,texture,&frame[i],&pos);

        if(i==3) i=0;
        else i+=1;

        if(pos.x<=-pos.w)    pos.x=WIDTH;//-frame->w;
        else pos.x-=12;



        SDL_RenderPresent(render);
        countFrames++;

        int frameTicks = SDL_GetTicks();
        if( frameTicks-start < SCREEN_TICKS_PER_FRAME )
        {
        //Wait remaining time
        printf("%i: %f ",SCREEN_FPS,(float)SCREEN_TICKS_PER_FRAME - (frameTicks-start));
        SDL_Delay( SCREEN_TICKS_PER_FRAME - (float)(frameTicks-start) );
        }
        else            printf("FASTER %i: %f ",SCREEN_FPS,(float)SCREEN_TICKS_PER_FRAME - (frameTicks-start));

    }


    Close();

    return 0;
}
