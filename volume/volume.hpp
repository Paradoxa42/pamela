//
// volume.hpp for pamela in /home/amice_g/rendu/pamela/mount_part
// 
// Made by gabriel amice
// Login   <amice_g@epitech.net>
// 
// Started on  Fri Oct 21 12:01:17 2016 gabriel amice
// Last update Sun Oct 23 12:38:29 2016 gabriel amice
//

#ifndef VOLUME_HPP_
# define VOLUME_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/mount.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <dirent.h>

class Volume
{
public:
  Volume();
  ~Volume();

  void getKey();	// Gets the encryption key (ideally, user's password)
  void makeVolume();	// Checks if volume exists. If not, creates it.
  void mountVolume();	// Mounts the created volume to current user's home.
  void encryptVolume();	// Encrypts the volume.
  void decryptVolume();	// Decrypts the volume.

private:
  unsigned char *iv;
  unsigned char *key;
  std::string path;
  std::string homedir;
  std::string mount_path;
};

#endif
