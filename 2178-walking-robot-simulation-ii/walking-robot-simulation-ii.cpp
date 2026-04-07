class Robot {
private:
    int w, h, perim;
    int x, y;
    string dir;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perim = 2 * (w + h) - 4;
        x = 0;
        y = 0;
        dir = "East";
    }
    
    void step(int num) {
        int move = num % perim;
        
        // Full cycle'da başlangıca dönünce yön South olmalı
        if (move == 0 && x == 0 && y == 0) {
            dir = "South";
            return;
        }
        
        while (move > 0) {
            if (dir == "East") {
                int canMove = min(move, w - 1 - x);
                x += canMove;
                move -= canMove;
                if (move > 0) dir = "North";
            }
            else if (dir == "North") {
                int canMove = min(move, h - 1 - y);
                y += canMove;
                move -= canMove;
                if (move > 0) dir = "West";
            }
            else if (dir == "West") {
                int canMove = min(move, x);
                x -= canMove;
                move -= canMove;
                if (move > 0) dir = "South";
            }
            else { // South
                int canMove = min(move, y);
                y -= canMove;
                move -= canMove;
                if (move > 0) dir = "East";
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dir;
    }
};