#include "image_display.hpp"



int main(int argc, char *argv[])
{

   if(argc < 1)
   {
	   cout << "    Usage: " << argv[0] << " <input_image> [<gt_word1> ... <gt_wordN>]" << endl;
	   return(0);
   }
   
   //obj creation
   image_display id;


   if(strcmp(argv[1], "webcam") == 0)
   {
	   id.read_cam();
   }
   if(strcmp(argv[1], "readimage") == 0)
   {
	   id.read_image();
   }

   return 0;


}
