#include<../include/animation.h>

 void Animation::animate(int dir, sf::IntRect &spritesheet, sf::Sprite &spr, float &timer){
    
    if (timer > 0.2f)
    {
        
       switch (dir)
        {
        case 1: //right
            spritesheet.top = 0;
            if (spritesheet.left == 5)
            {
                spritesheet.left = 0;
            }
            else{
                spritesheet.left += 5;
            }
            
            break;
        case 2: //left
            spritesheet.top = 5;
            if (spritesheet.left == 0)
            {
                spritesheet.left = 5;
            }
            else{
                spritesheet.left -= 5;
            }
            break;
        case 3: //up
            spritesheet.top = 10;
            if (spritesheet.left == 5)
            {
                spritesheet.left = 0;
            }
            else{
                spritesheet.left += 5;
            }
            break;
        case 4: //down
            spritesheet.top = 10;
            if (spritesheet.left == 0)
            {
                spritesheet.left = 5;
            }
            else{
                spritesheet.left -= 5;
            }
            break;
        case 5: //standing
            
            break;
        default:
            break;
        }
    timer = 0;
    spr.setTextureRect(spritesheet);
    }
};