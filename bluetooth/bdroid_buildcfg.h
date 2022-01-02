/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#pragma push_macro("PROPERTY_VALUE_MAX")

#include <cutils/properties.h>
#include <string.h>

static inline const char* BtmGetDefaultName()
{
    char product_device[PROPERTY_VALUE_MAX];
    property_get("ro.product.name", product_device, "");

    if (strstr(product_device, "x1sxxx"))
        return "Galaxy S20 5G";

    if (strstr(product_device, "x1sxx"))
        return "Galaxy S20";

    if (strstr(product_device, "y2sxxx"))
        return "Galaxy S20+ 5G";

    if (strstr(product_device, "y2sxx"))
        return "Galaxy S20+";

    if (strstr(product_device, "z3sxxx"))
        return "Galaxy S20 Ultra 5G";

    // Fallback to Default
    return "Samsung Galaxy";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()

/*
 * Toggles support for vendor specific extensions such as RPA offloading,
 * feature discovery, multi-adv etc.
 */
#define BLE_VND_INCLUDED TRUE

/* 'strings libbluetooth.so' */
#define BTA_AV_SINK_INCLUDED TRUE

#pragma pop_macro("PROPERTY_VALUE_MAX")

#endif /* _BDROID_BUILDCFG_H */
