/*******************************************************************************
 * File Name: DLLLoader
 * Owner: Sahar Moalem
 * Reviewer: Shani
 * Review status: Approved
 ******************************************************************************/
#ifndef  ILRD_RD1645_DLL_LOADER_HPP
#define  ILRD_RD1645_DLL_LOADER_HPP

#include <string>           // string
#include <unordered_map>    // unordered_map

namespace ilrd
{
class DLLLoader
{
public:
    DLLLoader() = default;
    ~DLLLoader();
    DLLLoader(const DLLLoader& other) = delete;
    DLLLoader& operator=(const DLLLoader& other) = delete;

    void Load(std::string file_name);
    void Unload(std::string file_name);

private:
    typedef void* dl_handler;
    std::unordered_map<std::string, dl_handler> m_dll_map;
};
}

#endif