//
// luks.hpp for luks in /home/amice_g/pamela/volume
// 
// Made by gabriel amice
// Login   <amice_g@epitech.net>
// 
// Started on  Wed Oct 26 01:01:39 2016 gabriel amice
// Last update Wed Oct 26 01:01:40 2016 gabriel amice
//

#ifndef LUKS_HPP_
# define LUKS_HPP_

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <pwd.h>
#include <map>

class Luks
{
public:
  Luks(std::string n_password);
  ~Luks();

  void mountLuks(void);
  void unmountLuks(void);
  
private:
  std::string password;
  std::string user_name;
  std::string user_home;
  std::string user_luks;
  std::string luks_name;

  std::map<std::string, std::string> partitions;
};

#endif
