#pragma once
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <string>
#include "QrCode.hpp"
#include "QrToPng.h"
#include "TinyPngOut.hpp"

namespace fusionLib{
    class Init{
        public:
            void EnableGui(){
                GuiEnable();
            }
            
            void WindowInit(int width, int height, const char* title){
                InitWindow(width, height, title);
            }

            void FPS(int x){
                SetTargetFPS(x);
            }

            void StartDrawing(){
                BeginDrawing();
            }

            void CanvasClear(Color color){
                ClearBackground(color);
            }

            void StopDrawing(){
                EndDrawing();
            }

            void WindowClose(){
                CloseWindow();
            }


    };

    class Button{

        int x, y, width, height;
        char* text;

        public:



        /*
        @param x: x position of the button
        @param y: y position of the button
        @param width: width of the button
        @param height: height of the button
        @param text: text to be displayed on the button*/
            int numberOfClicks = 0;
            Button(int x, int y, int width, int height, char* text){
                this->x = x;
                this->y = y;
                this->width = width;
                this->height = height;
                this->text = text;
            }

            int m_x = x;
            int m_y = y;
            int m_width = width;
            int m_height = height;
            
            bool DrawButton(){
                return GuiButtonWithClick((Rectangle){this->x, this->y, this->width, this->height}, this->text);
            }

            void SetText(char* text){
                this->text = text;
            }

            void SetPosition(int x, int y){
                this->x = x;
                this->y = y;
            }

            void SetSize(int width, int height){
                this->width = width;
                this->height = height;
            }

            bool GuiButtonWithClick(Rectangle bounds, char *text){
                GuiControlState state = guiState;
                bool pressed = false;

                // Update control
                //--------------------------------------------------------------------
                if ((state != GUI_STATE_DISABLED) && !guiLocked)
                {
                    Vector2 mousePoint = GetMousePosition();

                    // Check button state
                    if (CheckCollisionPointRec(mousePoint, bounds))
                    {
                        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state = GUI_STATE_PRESSED;
                        else state = GUI_STATE_FOCUSED;

                        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) pressed = true;
                        //rombotics25
                        if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) state = GUI_STATE_PRESSED;
                        else state = GUI_STATE_FOCUSED;

                        if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) pressed = true;
                        //rombotics25//
                    }
                }
                //--------------------------------------------------------------------

                // Draw control
                //--------------------------------------------------------------------
                GuiDrawRectangle(bounds, GuiGetStyle(BUTTON, BORDER_WIDTH), Fade(GetColor(GuiGetStyle(BUTTON, BORDER + (state*3))), guiAlpha), Fade(GetColor(GuiGetStyle(BUTTON, BASE + (state*3))), guiAlpha));
                GuiDrawText(text, GetTextBounds(BUTTON, bounds), GuiGetStyle(BUTTON, TEXT_ALIGNMENT), Fade(GetColor(GuiGetStyle(BUTTON, TEXT + (state*3))), guiAlpha));
                //------------------------------------------------------------------

                return pressed;
            }

            const char* IntToText(int number){
                const char *text = std::to_string(number).c_str();
                return text;
            }

            void DrawIntTextToButton(int number, int x, int y, Color color){
                const char *text = std::to_string(number).c_str();
                DrawText(text, x, y, 20, color);
            }

            void DrawTextToButton(char* text, int x, int y, Color color){
                DrawText(text, x, y, 20, color);
            }


    };

    class TextBox{
            
            int x, y, width, height, fontSize, editMode;
            char* text;
    
            public:
                TextBox(int x, int y, int width, int height, char* text, int fontSize, bool editMode){
                    this->x = x;
                    this->y = y;
                    this->width = width;
                    this->height = height;
                    this->text = text;
                    this->fontSize = fontSize;
                    this->editMode = editMode;
                }
    
                void DrawTextBox(){
                    GuiTextBox((Rectangle){this->x, this->y, this->width, this->height}, this->text, this->fontSize, this->editMode);
                }
    
                void SetText(char* text){
                    this->text = text;
                }
    
                void SetPosition(int x, int y){
                    this->x = x;
                    this->y = y;
                }
    
                void SetSize(int width, int height){
                    this->width = width;
                    this->height = height;
                }

                std::string GetText(){
                    return std::string(this->text);
                }
    
        };
    class QR: public QrToPng{
        public:
            QR();

            void GenerateQR(std::string text, int size, int minModulePixelSize, std::string fileName, bool overwriteExistingFile, qrcodegen::QrCode::Ecc ecc){
                auto m_qr = QrToPng(fileName, size, minModulePixelSize, text, overwriteExistingFile, ecc);
                m_qr.writeToPNG();
            }

    };        
    };


