//example program

#include "include/fusionLib.h"

int main(){

    std::string filename = "6672.png";

    fusionLib::Init init;
    fusionLib::Button upperHub(100, 100, 100, 50, "Upper Hub");
    fusionLib::Button lowerHub(100, 200, 100, 50, "Lower Hub");
    fusionLib::Button hangar(100, 300, 100, 50, "Hangar");

    

//       fusionLib::QR qr('6672.png', 300, 3, "Hello WOrld1", true, qrcodegen::QrCode::Ecc::MEDIUM);
    //here, '6672.png' is an int. C?



    init.EnableGui(); //-> GuiEnable();
    init.WindowInit(800, 600, "Hello World"); //-> InitWindow(800, 600, "Hello World");
    init.FPS(60);



    while(!WindowShouldClose()){

    if(upperHub.DrawButton() == true && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)){
        --upperHub.numberOfClicks;

        if(upperHub.numberOfClicks < 0){
            upperHub.numberOfClicks = 0;
        }
        upperHub.IntToText(upperHub.numberOfClicks);
    }
        
    if(upperHub.DrawButton() == true && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
        ++upperHub.numberOfClicks;
        upperHub.IntToText(upperHub.numberOfClicks);
    }

    if(lowerHub.DrawButton() == true && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)){
        --lowerHub.numberOfClicks;

        if(lowerHub.numberOfClicks < 0){
            lowerHub.numberOfClicks = 0;
        }
        lowerHub.IntToText(upperHub.numberOfClicks);
    }
        
    if(lowerHub.DrawButton() == true && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
        ++lowerHub.numberOfClicks;
        lowerHub.IntToText(lowerHub.numberOfClicks);
    }

    if(hangar.DrawButton() == true && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)){
        --hangar.numberOfClicks;

        if(hangar.numberOfClicks < 0){
            hangar.numberOfClicks = 0;
        }
        hangar.IntToText(hangar.numberOfClicks);
    }

    if(hangar.DrawButton() == true && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
        ++hangar.numberOfClicks;
        hangar.IntToText(hangar.numberOfClicks);
    }




    init.StartDrawing(); //-> BeginDrawing();

        init.CanvasClear(BLACK); //-> ClearBackground(BLACK);

        upperHub.DrawButton(); //-> GuiButton((Rectangle){x, y, width, height}, text);
        upperHub.DrawIntTextToButton(upperHub.numberOfClicks, 100, 100, BLUE); //-> DrawText(text, x, y, color);
        lowerHub.DrawButton();
        lowerHub.DrawIntTextToButton(lowerHub.numberOfClicks, 100, 200, BLUE);
        hangar.DrawButton();
        switch(hangar.numberOfClicks){
            case 1:
                hangar.DrawTextToButton("Low", 100, 300, BLUE);
                break;
            case 2:
                hangar.DrawTextToButton("Mid", 100, 300, BLUE);
                break;
            case 3:
                hangar.DrawTextToButton("High", 100, 300, BLUE);
                break;
            case 4:
                hangar.DrawTextToButton("Traversal", 100, 300, BLUE);
                break;
            case 5:
                hangar.numberOfClicks = 4;
        }

    init.StopDrawing();//-> EndDrawing();
    }

 
    init.WindowClose(); //-> CloseWindow();



    return 0;
}