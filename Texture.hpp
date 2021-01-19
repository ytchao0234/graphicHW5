class Texture
{
    public:
        const int number;
        unsigned int *id;
        unsigned char circle[64][64][4];

        Texture(): number(0)
        {
            id = NULL;
        }

        Texture( unsigned int n ): number(n)
        {
            id = new unsigned int[n];
        }

        void Create_Texture_Circle()
        {
            int  y, x, i, temp;
            for(y=0;y<64;y++)
            {
                for(x=0;x<64;x++)
                {
                    circle[y][x][0] = 100;
                    circle[y][x][1] = 100;
                    circle[y][x][2] = 100;
                    circle[y][x][3] = 255;
                }
            }
            for(y=16,x=0;y<48;y++)
            {
                if(y<=20 && y>=17)
                    x=x+2;
                else if(y==22 || y==25 || y==31)
                    x=x+1;
                else if(y==42 || y==39 || y==33)
                    x=x-1;
                else if(y<=47 && y>=44)
                    x=x-2;
                temp=x;
                for(x=0;x<temp;x++)
                {
                    circle[y][x][0] = 150;
                    circle[y][x][1] = 150;
                    circle[y][x][2] = 150;
                    circle[y][x][3] = 255;
                }
                for(x=64-temp;x<64;x++)
                {
                    circle[y][x][0] = 150;
                    circle[y][x][1] = 150;
                    circle[y][x][2] = 150;
                    circle[y][x][3] = 255;
                }
                x=temp;
            }

            for(x=16,y=0;x<48;x++)
            {
                if(x<=20 && x>=17)
                    y=y+2;
                else if(x==22 || x==25 || x==31)
                    y=y+1;
                else if(x==42 || x==39 || x==33)
                    y=y-1;
                else if(x<=47 && x>=44)
                    y=y-2;
                temp=y;
                for(y=0;y<temp;y++)
                {
                    circle[y][x][0] = 200;
                    circle[y][x][1] = 200;
                    circle[y][x][2] = 200;
                    circle[y][x][3] = 255;
                }
                for(y=64-temp;y<64;y++)
                {
                    circle[y][x][0] = 200;
                    circle[y][x][1] = 200;
                    circle[y][x][2] = 200;
                    circle[y][x][3] = 255;
                }
                y=temp;
            }
            for(i=0;i<61;i++)
            {
                for(y=i;y<4+i;y++)
                {
                    for(x=i;x<4+i;x++)
                    {
                        circle[y][x][0] = 255;
                        circle[y][x][1] = 255;
                        circle[y][x][2] = 255;
                        circle[y][x][3] = 255;
                    }
                }
            }
            for(i=0;i<61;i++)
            {
                for(y=i;y<4+i;y++)
                {
                    for(x=60-i;x<64-i;x++)
                    {
                        circle[y][x][0] = 255;
                        circle[y][x][1] = 255;
                        circle[y][x][2] = 255;
                        circle[y][x][3] = 255;
                    }
                }
            }
        }

        void setAttributes()
        {
            Create_Texture_Circle();
            
            glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
            glBindTexture( GL_TEXTURE_2D , id[0] );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
            glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 64 , 64 , 0 , GL_RGBA ,
                          GL_UNSIGNED_BYTE , circle );
        }
};