#ifndef LCD_TABLE_H
#define LCD_TABLE_H

#include <fstream>

#define ArrayLimit 9

	struct Table{
	          char character;
              char LCDSmall[ArrayLimit];
              char LCDBig[ArrayLimit];
            };	   	 	


class LCD_Table
{
	public:
		LCD_Table();
		~LCD_Table();
		void Run();
			 
		private:                                                      
			   				   																	
			void Engine(std::ofstream& out)const;
			void About();
			void Help();
            void Compare(char& character,const Table LCD_Table[],std::ofstream& out)const;
            Table* CommonCathode(const Table OringinalTable[])const;
            int fTableSize;
};


#endif  //LCD_TABLE_H
