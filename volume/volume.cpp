//
// volume.cpp for pamela in /home/amice_g/rendu/pamela/mount_part
// 
// Made by gabriel amice
// Login   <amice_g@epitech.net>
// 
// Started on  Fri Oct 21 12:02:02 2016 gabriel amice
// Last update Sun Oct 23 16:46:46 2016 gabriel amice
//

#include "volume.hpp"

Volume::Volume()
{
  struct passwd *pw = getpwuid(getuid());

  homedir = pw->pw_dir;
  path = homedir + "/EV";
  mount_path = homedir + "/EV_mounted";
  std::cout << homedir << std::endl;
  std::cout << path << std::endl;
}

Volume::~Volume()
{

}

void Volume::getKey()
{
  
  //SecByteBlock key(0x00, AES::DEFAULT_KEYLENGTH);
  //rnd.GenerateBlock( key, key.size() );
  std::string test = "TestKey.jpg";
}

void Volume::makeVolume()
{
  mkdir(path.c_str(), S_IRUSR | S_IWUSR | S_IXUSR);
}

void Volume::mountVolume()
{
  mount(path.c_str(), mount_path.c_str(), "ext4", MS_BIND, NULL);
}

void Volume::encryptVolume()
{
  DIR *dir;
  int status;
  std::string temp;
  struct dirent *ep;
  struct stat st_buff;

  dir = opendir(path.c_str());
  if (dir != NULL)
    {
      while (ep = readdir(dir))
	{
	  temp = path + "/" + ep->d_name;
	  std::cout << temp << std::endl;
	  status = stat(temp.c_str(), &st_buff);
	  if (S_ISREG (st_buff.st_mode))
	    {
	      std::cout << temp << " is a regular file.\n";
	    }
	  if (S_ISDIR (st_buff.st_mode))
	    {
	      std::cout << temp << " is a directory.\n";
	    }
	}
      closedir(dir);
    }
}

void Volume::decryptVolume()
{

}

int main()
{
  Volume vol;
  vol.makeVolume();
  vol.mountVolume();
  vol.encryptVolume();
  return (0);
}
