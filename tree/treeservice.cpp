#include "treeservice.h"

TreeService::TreeService()
{

}

TreeService* TreeService::instance = 0;
TreeService* TreeService::getInstance() {
    if(!TreeService::instance)
        TreeService::instance = new TreeService();
    return TreeService::instance;
}
