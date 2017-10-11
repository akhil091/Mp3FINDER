/* Mp3FINDER
   Author-> AKHIL CHANDAIL
   Student of 3rd Sem CSE A1
   MIET JAMMU
*/
#include<iostream>
#include<vector>     /*vectors use contiguous storage locations for their elements, which means that their elements 
								can also be accessed using offsets on regular pointers to its elements*/
#include<string.h>    //The string.h header defines one variable type, one macro, and various functions for manipulating arrays of characters.
#include<string>
#include<dirent.h>       /*dirent.h is a header file in the C standard POSIX library for the C programming language
							that constructs or facilitate directory traversing */
using namespace std;

class mp3 {
	public:
	string filename;
	string filepath; 
    mp3(char *f_name,string path)
    {

   for( int i=0; i<strlen(f_name); i++ )
    
        filename.push_back (f_name[i]);
    	 filepath=path;
    }   

	};

   vector<mp3> list;
   class directory{
	public:
	   DIR *dir;
	struct  dirent *ent;
	   directory (string x)
	    {
		dir= opendir ( x.c_str() );
            }
   
    bool lsDir()
	     {
    	if(ent->d_type==4)
    		return true;
    	
	else 
    		return false;
    	    }

    bool lsmp3()
	{
    	if ( ent->d_type==8 )
	    {
    		string temp;
    		for(int i=strlen(ent->d_name)-4; i<strlen(ent->d_name); i++)
    		    temp.push_back (ent->d_name[i]);

    		if( temp== ".mp3" )
    			return true;
    		else
    			return false;
    	   }	
    	else
    	       return false;  			        
    	
       }	
  };


 void findmp3 (string x){

	directory d(x);

	     if(d.dir!=NULL)
	{
		while( (d.ent= readdir(d.dir) )!= NULL )
			{
												//skips the file names with '.','..' and '.*'
                        if( strcmp( d.ent->d_name, ".")== 0 || strcmp( d.ent->d_name, "..")== 0 || d.ent->d_name[0] =='.')
		continue;
												//checks for directory
			if( d.lsDir() )
				{
				string temp (d.ent->d_name);
				temp = x + "/" + temp;
				findmp3 (temp);
				}
			                                                                        //test for mp3 files
			if( d.lsmp3() )
				{
				mp3 m( d.ent->d_name, x);
				list.push_back(m);               				        
				}	 
	  }
		closedir(d.dir);
     }
   }
 int main()
         {
	   findmp3 ( "." );

	    for( int i=0; i<list.size(); i++ )
		cout<< list[i].filename<< "\t" << list[i].filepath << endl;	
          }
