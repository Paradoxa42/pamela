//
// luks.cpp for luks in /home/amice_g/pamela/volume
// 
// Made by gabriel amice
// Login   <amice_g@epitech.net>
// 
// Started on  Wed Oct 26 01:01:33 2016 gabriel amice
// Last update Wed Oct 26 01:01:34 2016 gabriel amice
//

#include "luks.hpp"

Luks::Luks(std::string n_password) : password(n_password)
{
  struct passwd *pw = getpwuid(getuid());

  partitions.insert(std::pair<std::string,std::string>("root","sda5"));
  partitions.insert(std::pair<std::string,std::string>("gabriel amice","sda6"));
  
  user_name = pw->pw_name;
  user_home = pw->pw_dir;
  luks_name = user_name + "Vol";
  user_luks = user_home + '/' + luks_name;
  
  std::cout << "Username : " << user_name << std::endl;
  std::cout << "Userhome : " << user_home << std::endl;
  std::cout << "Luksname : " << luks_name << std::endl;
  std::cout << "Userluks : " << user_luks << std::endl;
}

Luks::~Luks()
{

}

void Luks::mountLuks(void)
{
  std::string command;

  command = "echo " + password + " | cryptsetup luksOpen /dev/" + partitions[user_name] + ' ' + luks_name;
  system(command.c_str());

  mkdir(user_luks.c_str(), S_IRUSR | S_IWUSR | S_IXUSR);
  
  command = "mount /dev/mapper/" + luks_name + ' ' + user_luks;
  system(command.c_str());
}

void Luks::unmountLuks(void)
{
  std::string command;

  command = "umount " + user_luks;
  system(command.c_str());
  command = "cryptsetup luksClose " + luks_name;
  system(command.c_str());

  rmdir(user_luks.c_str());
}

int	main()
{
  Luks Volume("root");
  Volume.mountLuks();
  Volume.unmountLuks();
  return (0);
}
