#include <stdio.h>
#include <raylib.h>


int main()
{
	printf("Hello World");

	InitWindow(800, 600, "Test");
	SetWindowState(FLAG_VSYNC_HINT);
	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawCircle(GetScreenWidth()/2,GetScreenHeight()/2,5,WHITE);
			DrawFPS(10,10);
			DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}