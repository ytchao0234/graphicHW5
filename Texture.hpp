class Texture
{
    public:
        const int number;
        unsigned int *id;
        unsigned char circle[64][64][4];
        unsigned char seaFloor[256][256][4];
        unsigned char seaSurface[256][256][4];
        unsigned char starryNight[256][256][4];
        unsigned char cloud[256][256][4];

        Texture(): number(0)
        {
            id = NULL;
        }

        Texture( unsigned int n ): number(n)
        {
            id = new unsigned int[n];
        }

        ~Texture()
        {
            if( number == 1 )
                delete id;
            else if( number > 1 )
                delete[] id;
        }

        void ReadBMPFile( string filename, unsigned char textureData[256][256][4] )
        {
            FILE* fp = fopen(filename.c_str(), "rb");

            unsigned char info[138];
            fread(info, sizeof(unsigned char), 138, fp);

            unsigned char *image = new unsigned char[256*256*4];
            fread(image, sizeof(unsigned char), 256*256*4, fp);

            fclose(fp);

            for( int i = 0; i < 256*256*4; i += 4)
            {
                unsigned char temp = image[i];
                image[i] = image[i+2];
                image[i+2] = temp;

                textureData[i / 4 / 256][i / 4 % 256][0] = image[i];
                textureData[i / 4 / 256][i / 4 % 256][1] = image[i+1];
                textureData[i / 4 / 256][i / 4 % 256][2] = image[i+2];
                textureData[i / 4 / 256][i / 4 % 256][3] = image[i+3];
            }

            // for( int i = 0; i < 256*256*4 - 4; i+=4 )
            // {
            //     cout << (int)image[i] << ", " << (int)image[i+1] << ", " << (int)image[i+2] << ", " << (int)image[i+3] << endl;
            // }

            delete[] image;
        }

        void setAttributes()
        {
            ReadBMPFile("./image/sea-floor.bmp", seaFloor );
            
            glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
            glBindTexture( GL_TEXTURE_2D , id[0] );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
            glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 256 , 256 , 0 , GL_RGBA ,
                          GL_UNSIGNED_BYTE , seaFloor );

            ReadBMPFile("./image/sea-surface.bmp", seaSurface );
            
            glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
            glBindTexture( GL_TEXTURE_2D , id[1] );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
            glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 256 , 256 , 0 , GL_RGBA ,
                          GL_UNSIGNED_BYTE , seaSurface );

            ReadBMPFile("./image/starry-night.bmp", starryNight );
            
            glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
            glBindTexture( GL_TEXTURE_2D , id[2] );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
            glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 256 , 256 , 0 , GL_RGBA ,
                          GL_UNSIGNED_BYTE , starryNight );

            ReadBMPFile("./image/cloud.bmp", cloud );
            
            glPixelStorei( GL_UNPACK_ALIGNMENT , 4 );
            glBindTexture( GL_TEXTURE_2D , id[3] );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_MIRRORED_REPEAT );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
            glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , 256 , 256 , 0 , GL_RGBA ,
                          GL_UNSIGNED_BYTE , cloud );

        }
};