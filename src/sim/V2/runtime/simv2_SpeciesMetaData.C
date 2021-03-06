// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <cstring>
#include <vectortypes.h>
#include "VisItDataInterfaceRuntime.h"
#include "VisItDataInterfaceRuntimeP.h"

#include "simv2_SpeciesMetaData.h"

struct VisIt_SpeciesMetaData : public VisIt_ObjectBase
{
    VisIt_SpeciesMetaData();
    virtual ~VisIt_SpeciesMetaData();

    std::string          name;
    std::string          meshName;
    std::string          materialName;
    std::vector<visit_handle> speciesNames;
};

VisIt_SpeciesMetaData::VisIt_SpeciesMetaData() : VisIt_ObjectBase(VISIT_SPECIESMETADATA)
{
    name = "";
    meshName = "";
    materialName = "";
}

VisIt_SpeciesMetaData::~VisIt_SpeciesMetaData()
{
}

static VisIt_SpeciesMetaData *
GetObject(visit_handle h, const char *fname)
{
    char tmp[100];
    VisIt_SpeciesMetaData *obj = (VisIt_SpeciesMetaData *)VisItGetPointer(h);
    if(obj != NULL)
    {
        if(obj->objectType() != VISIT_SPECIESMETADATA)
        {
            snprintf(tmp, 100, "%s: The provided handle does not point to "
                "a SpeciesMetaData object.", fname);
            VisItError(tmp);
            obj = NULL;
        }
    }
    else
    {
        snprintf(tmp, 100, "%s: An invalid handle was provided.", fname);
        VisItError(tmp);
    }

    return obj;
}

/*******************************************************************************
 * Public functions, available to C 
 ******************************************************************************/

int
simv2_SpeciesMetaData_alloc(visit_handle *h)
{
    *h = VisItStorePointer(new VisIt_SpeciesMetaData);
    return (*h != VISIT_INVALID_HANDLE) ? VISIT_OKAY : VISIT_ERROR;
}

int
simv2_SpeciesMetaData_free(visit_handle h)
{
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_free");
    if(obj != NULL)
    {
        delete obj;
        VisItFreePointer(h);
        retval = VISIT_OKAY;
    }
    return retval;
}

int
simv2_SpeciesMetaData_setName(visit_handle h, const char *val)
{
    if(val == NULL)
    {
        VisItError("An invalid string was provided for name");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_setName");
    if(obj != NULL)
    {
        obj->name = val;
        retval = VISIT_OKAY;
    }
    return retval;
}

int
simv2_SpeciesMetaData_getName(visit_handle h, char **val)
{
    if(val == NULL)
    {
        VisItError("simv2_SpeciesMetaData_getName: Invalid address.");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_getName");
    if(obj != NULL)
    {
        *val = (char*)malloc(obj->name.size() + 1);
        strcpy(*val, obj->name.c_str());
        retval = VISIT_OKAY;
    }
    else
        *val = NULL;
    return retval;
}

int
simv2_SpeciesMetaData_setMeshName(visit_handle h, const char *val)
{
    if(val == NULL)
    {
        VisItError("An invalid string was provided for meshName");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_setMeshName");
    if(obj != NULL)
    {
        obj->meshName = val;
        retval = VISIT_OKAY;
    }
    return retval;
}

int
simv2_SpeciesMetaData_getMeshName(visit_handle h, char **val)
{
    if(val == NULL)
    {
        VisItError("simv2_SpeciesMetaData_getMeshName: Invalid address.");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_getMeshName");
    if(obj != NULL)
    {
        *val = (char*)malloc(obj->meshName.size() + 1);
        strcpy(*val, obj->meshName.c_str());
        retval = VISIT_OKAY;
    }
    else
        *val = NULL;
    return retval;
}

int
simv2_SpeciesMetaData_setMaterialName(visit_handle h, const char *val)
{
    if(val == NULL)
    {
        VisItError("An invalid string was provided for materialName");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_setMaterialName");
    if(obj != NULL)
    {
        obj->materialName = val;
        retval = VISIT_OKAY;
    }
    return retval;
}

int
simv2_SpeciesMetaData_getMaterialName(visit_handle h, char **val)
{
    if(val == NULL)
    {
        VisItError("simv2_SpeciesMetaData_getMaterialName: Invalid address.");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_getMaterialName");
    if(obj != NULL)
    {
        *val = (char*)malloc(obj->materialName.size() + 1);
        strcpy(*val, obj->materialName.c_str());
        retval = VISIT_OKAY;
    }
    else
        *val = NULL;
    return retval;
}

int
simv2_SpeciesMetaData_addSpeciesName(visit_handle h, visit_handle val)
{
    if(simv2_ObjectType(val) != VISIT_NAMELIST)
    {
        VisItError("Only NameList objects can be inserted as species names");
        return VISIT_ERROR;
    }
    if(val == VISIT_INVALID_HANDLE)
    {
        VisItError("An invalid handle was provided for speciesNames");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_addSpeciesName");
    if(obj != NULL)
    {
        obj->speciesNames.push_back(val);
        retval = VISIT_OKAY;
    }
    return retval;
}

int
simv2_SpeciesMetaData_getNumSpeciesName(visit_handle h, int *val)
{
    if(val == NULL)
    {
        VisItError("simv2_SpeciesMetaData_getNumSpeciesName: Invalid address");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_getNumSpeciesName");
    if(obj != NULL)
    {
        *val = obj->speciesNames.size();
        retval = VISIT_OKAY;
    }
    else
        *val = 0;
    return retval;
}

int
simv2_SpeciesMetaData_getSpeciesName(visit_handle h, int i, visit_handle *val)
{
    if(val == NULL)
    {
        VisItError("simv2_SpeciesMetaData_getSpeciesName: Invalid address");
        return VISIT_ERROR;
    }
    int retval = VISIT_ERROR;
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_getSpeciesName");
    if(obj != NULL && i >= 0 && i < (int)obj->speciesNames.size())
    {
        *val = obj->speciesNames[i];
        retval = VISIT_OKAY;
    }
    else
        *val = VISIT_INVALID_HANDLE;
    return retval;
}

int
simv2_SpeciesMetaData_check(visit_handle h)
{
    VisIt_SpeciesMetaData *obj = GetObject(h, "simv2_SpeciesMetaData_check");
    int retval = VISIT_ERROR;
    if(obj != NULL)
    {
        if(obj->name == "")
        {
            VisItError("SpeciesMetaData needs a name");
            return VISIT_ERROR;
        }
        if(obj->meshName == "")
        {
            VisItError("SpeciesMetaData needs a mesh name");
            return VISIT_ERROR;
        }
        if(obj->materialName == "")
        {
            VisItError("SpeciesMetaData needs a material name");
            return VISIT_ERROR;
        }
        if(obj->speciesNames.empty())
        {
            VisItError("SpeciesMetaData needs species name lists");
            return VISIT_ERROR;
        }
        retval = VISIT_OKAY;
    }
    return retval;
}

