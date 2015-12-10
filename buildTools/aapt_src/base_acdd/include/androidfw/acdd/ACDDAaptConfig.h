//
//  AaptConfig.h
//  AaptExt
//
//  Created by BunnyBlue on 6/25/15.
//  Copyright © 2015 BunnyBlue. All rights reserved.
//

#ifndef __ACDD__AaptConfig_h
#define __ACDD__AaptConfig_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <map>

using namespace std;

#define ACDD_AAPT_CONFIG_SHARED_RESOURCES_SYMBOL "shared-resources-symbol"//prebuild Shared  Package Resouces
#define ACDD_AAPT_CONFIG_PKG_GROUP_ID "pkgGroupId"// plugin package group id
#define ACDD_AAPT_CONFIG_PKG_VERSION_NAME "versionName"//plugin package versionName
#define ACDD_AAPT_CONFIG_TYPE_PACKAGE_GROUP_ID 1
#define ACDD_AAPT_CONFIG_TYPE_SHARED_RESOURCE_TABLE 2
class ACDDAaptConfig
{

size_t packageGroupId;
std::string mSharedResourcePackageName;
std::string mSharedResourcePath;
std::string versionName;
bool  updateVersion;
public:
    static ACDDAaptConfig* getInstance()
    {
        static ACDDAaptConfig instance;
        return &instance;
    }
    //config
   bool  initACDDConig(std::string config,int configType);
  //  std::string getConfigByKey(const std::string key);
    size_t getPackageGroupId();
    std::string  getSharedResourcePackageName();
    std::string  getSharedResourcePath();
    std::string  getVersionName();
    bool  isUpdateVersion();
   int getSharedResource(std::string type,std::string name);
protected:
    struct Object_Creator
    {
        Object_Creator()
        {
            ACDDAaptConfig::getInstance();
        }
    };
    static Object_Creator _object_creator;
    std::string _conFilePath;

    std::map<std::string, std::string> options;
    bool read_file(std::istream& is);
    ACDDAaptConfig() {
updateVersion=false;
  packageGroupId=0x7f;
    }
    ~ACDDAaptConfig() {}
};

#endif /* AaptConfig_cpp */
/*
 config  should be
 pkg=io.github.bunnyblue.pkg
 preBuildJarPath=/Users/Downloads/prebuild.jar
 pkgGroupId=0x1a
 unusedkey=unusedvalue
 */
