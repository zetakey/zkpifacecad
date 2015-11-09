/*
 * Copyright (C) 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Holger Hans Peter Freyther
 * Copyright (C) 2010 Collabora Ltd.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "npapi.h"
#include "npruntime.h"
#include "npfunctions.h"

#include "pluginobject.h"
// Hardware.js generated headerFiles
#include <pifacecad.h>


#define uint16  unsigned short
#define int32   int32_t

// 1. Zetakey Add value for new functions here...
enum {
    ID_ZK_DEBUG_MSG = 0,
    ID_ZK_SET_STRVALUE,
    ID_ZK_GET_STRVALUE,
    ID_ZK_GET_MAC_ADDRESS,

    // 1. Zetakey Add ID for plugin functions here...
    // Hardware.js generated Method Indentifiers
ID_ZK_PIFACECAD_OPEN,ID_ZK_PIFACECAD_OPEN_NOINIT,ID_ZK_PIFACECAD_CLOSE,ID_ZK_PIFACECAD_LCD_INIT,ID_ZK_PIFACECAD_READ_SWITCHES,ID_ZK_PIFACECAD_READ_SWITCH,ID_ZK_PIFACECAD_LCD_WRITE,ID_ZK_PIFACECAD_LCD_SET_CURSOR,ID_ZK_PIFACECAD_LCD_SET_CURSOR_ADDRESS,ID_ZK_PIFACECAD_LCD_GET_CURSOR_ADDRESS,ID_ZK_PIFACECAD_LCD_CLEAR,ID_ZK_PIFACECAD_LCD_HOME,ID_ZK_PIFACECAD_LCD_DISPLAY_ON,ID_ZK_PIFACECAD_LCD_DISPLAY_OFF,ID_ZK_PIFACECAD_LCD_BLINK_ON,ID_ZK_PIFACECAD_LCD_BLINK_OFF,ID_ZK_PIFACECAD_LCD_CURSOR_ON,ID_ZK_PIFACECAD_LCD_CURSOR_OFF,ID_ZK_PIFACECAD_LCD_BACKLIGHT_ON,ID_ZK_PIFACECAD_LCD_BACKLIGHT_OFF,ID_ZK_PIFACECAD_LCD_MOVE_LEFT,ID_ZK_PIFACECAD_LCD_MOVE_RIGHT,ID_ZK_PIFACECAD_LCD_LEFT_TO_RIGHT,ID_ZK_PIFACECAD_LCD_RIGHT_TO_LEFT,ID_ZK_PIFACECAD_LCD_AUTOSCROLL_ON,ID_ZK_PIFACECAD_LCD_AUTOSCROLL_OFF,ID_ZK_PIFACECAD_LCD_SEND_COMMAND,ID_ZK_PIFACECAD_LCD_SEND_DATA,ID_ZK_PIFACECAD_LCD_SEND_BYTE,ID_ZK_PIFACECAD_LCD_SET_RS,ID_ZK_PIFACECAD_LCD_SET_RW,ID_ZK_PIFACECAD_LCD_SET_ENABLE,ID_ZK_PIFACECAD_LCD_SET_BACKLIGHT,ID_ZK_PIFACECAD_LCD_PULSE_ENABLE,ID_ZK_COLROW2ADDRESS,ID_ZK_ADDRESS2COL,ID_ZK_ADDRESS2ROW,


    NUM_METHOD_IDENTIFIERS
};

static NPIdentifier     pluginMethodIdentifiers     [NUM_METHOD_IDENTIFIERS];
static const NPUTF8*    pluginMethodIdentifierNames [NUM_METHOD_IDENTIFIERS] = {
    "zkDebugMessage",
    "setTestString",
    "getTestString",

    //helper functions
    "getMacAddress",

    //2 . plugin method (same javascipt method name). Also, try to use the name as the C function.
    //The inital function with zk_ prefix
    // Hardware.js generated Function List
"pifacecad_open","pifacecad_open_noinit","pifacecad_close","pifacecad_lcd_init","pifacecad_read_switches","pifacecad_read_switch","pifacecad_lcd_write","pifacecad_lcd_set_cursor","pifacecad_lcd_set_cursor_address","pifacecad_lcd_get_cursor_address","pifacecad_lcd_clear","pifacecad_lcd_home","pifacecad_lcd_display_on","pifacecad_lcd_display_off","pifacecad_lcd_blink_on","pifacecad_lcd_blink_off","pifacecad_lcd_cursor_on","pifacecad_lcd_cursor_off","pifacecad_lcd_backlight_on","pifacecad_lcd_backlight_off","pifacecad_lcd_move_left","pifacecad_lcd_move_right","pifacecad_lcd_left_to_right","pifacecad_lcd_right_to_left","pifacecad_lcd_autoscroll_on","pifacecad_lcd_autoscroll_off","pifacecad_lcd_send_command","pifacecad_lcd_send_data","pifacecad_lcd_send_byte","pifacecad_lcd_set_rs","pifacecad_lcd_set_rw","pifacecad_lcd_set_enable","pifacecad_lcd_set_backlight","pifacecad_lcd_pulse_enable","colrow2address","address2col","address2row",

};

enum {
    ID_PROPERTY_PROPERTY = 0,
    ID_PROPERTY_EVENT_LOGGING,
    ID_PROPERTY_HAS_STREAM,
    ID_PROPERTY_LOG_DESTROY,
    ID_PROPERTY_RETURN_ERROR_FROM_NEWSTREAM,
    ID_PROPERTY_PRIVATE_BROWSING_ENABLED,
    ID_PROPERTY_CACHED_PRIVATE_BROWSING_ENABLED,
    ID_PROPERTY_THROW_EXCEPTION_PROPERTY,
    ID_LAST_SET_WINDOW_ARGUMENTS,
    NUM_PROPERTY_IDENTIFIERS
};

static NPIdentifier     pluginPropertyIdentifiers       [NUM_PROPERTY_IDENTIFIERS];
static const NPUTF8*    pluginPropertyIdentifierNames   [NUM_PROPERTY_IDENTIFIERS] = {
    "property",
    "eventLoggingEnabled",
    "hasStream",
    "logDestroy",
    "returnErrorFromNewStream",
    "privateBrowsingEnabled",
    "cachedPrivateBrowsingEnabled",
    "testThrowExceptionProperty",
    "lastSetWindowArguments"
};

static NPNetscapeFuncs* gBrowser;

static char* stringMemalloc(PluginObject* obj, const NPString& string)
{

    char* result = (char *)obj->browser->memalloc(string.UTF8Length + 1);
    memcpy(result, string.UTF8Characters, string.UTF8Length);
    result[string.UTF8Length] = '\0';
    return result;
}

static void stringFree(PluginObject* obj, char* string)
{
    obj->browser->memfree(string);
}

static void executeScript(const PluginObject* obj, const char* script)
{
    NPObject*   windowScriptObject;
    NPVariant   browserResult;
    NPString    npScript;

    printf("%s %s\n", __FILE__, __FUNCTION__);

    npScript.UTF8Characters = script;
    npScript.UTF8Length     = strlen(script);

    obj->browser->getvalue(obj->npp, NPNVWindowNPObject, &windowScriptObject);
    obj->browser->evaluate(obj->npp, windowScriptObject, &npScript, &browserResult);
    obj->browser->releasevariantvalue(&browserResult);
}



//3. Implementation of the core functions
//===========================================================================//
// Hardware.js generated Functions Implementation

static bool zk_pifacecad_open(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	int zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 0 ))
	{
		zk_outputData = (int)pifacecad_open();
		printf("\n[HardwareJS Plugin] : pifacecad_open is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_open_noinit(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	int zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 0 ))
	{
		zk_outputData = (int)pifacecad_open_noinit();
		printf("\n[HardwareJS Plugin] : pifacecad_open_noinit is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_close(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_close();
		printf("\n[HardwareJS Plugin] : pifacecad_close is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_init(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_init();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_init is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_read_switches(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 0 ))
	{
		zk_outputData = (uint8_t)pifacecad_read_switches();
		printf("\n[HardwareJS Plugin] : pifacecad_read_switches is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_read_switch(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t switch_num;
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		switch_num = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		zk_outputData = (uint8_t)pifacecad_read_switch(switch_num);
		printf("\n[HardwareJS Plugin] : pifacecad_read_switch is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_write(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	char* message = NULL;
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 1 ) && NPVARIANT_IS_STRING(args[0]))
	{
		NPString npString0 = NPVARIANT_TO_STRING(args[0]);
		message = stringMemalloc(obj, npString0);
		zk_outputData = (uint8_t)pifacecad_lcd_write(message);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_write is called ");
		stringFree(obj, message);
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_set_cursor(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t col;
	uint8_t row;
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 2 ) && NPVARIANT_IS_DOUBLE(args[0]) && NPVARIANT_IS_DOUBLE(args[1]))
	{
		col = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		row = (uint8_t)NPVARIANT_TO_DOUBLE(args[1]);
		zk_outputData = (uint8_t)pifacecad_lcd_set_cursor(col, row);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_set_cursor is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_set_cursor_address(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t address;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		address = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_set_cursor_address(address);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_set_cursor_address is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_get_cursor_address(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 0 ))
	{
		zk_outputData = (uint8_t)pifacecad_lcd_get_cursor_address();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_get_cursor_address is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_clear(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_clear();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_clear is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_home(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_home();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_home is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_display_on(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_display_on();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_display_on is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_display_off(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_display_off();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_display_off is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_blink_on(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_blink_on();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_blink_on is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_blink_off(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_blink_off();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_blink_off is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_cursor_on(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_cursor_on();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_cursor_on is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_cursor_off(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_cursor_off();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_cursor_off is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_backlight_on(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_backlight_on();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_backlight_on is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_backlight_off(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_backlight_off();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_backlight_off is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_move_left(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_move_left();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_move_left is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_move_right(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_move_right();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_move_right is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_left_to_right(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_left_to_right();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_left_to_right is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_right_to_left(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_right_to_left();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_right_to_left is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_autoscroll_on(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_autoscroll_on();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_autoscroll_on is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_autoscroll_off(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_autoscroll_off();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_autoscroll_off is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_send_command(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t command;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		command = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_send_command(command);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_send_command is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_send_data(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t data;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		data = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_send_data(data);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_send_data is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_send_byte(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t byte;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		byte = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_send_byte(byte);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_send_byte is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_set_rs(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t state;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		state = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_set_rs(state);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_set_rs is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_set_rw(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t state;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		state = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_set_rw(state);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_set_rw is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_set_enable(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t state;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		state = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_set_enable(state);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_set_enable is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_set_backlight(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t state;
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		state = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		pifacecad_lcd_set_backlight(state);
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_set_backlight is called ");
		return true;
	}
	return false;
}
static bool zk_pifacecad_lcd_pulse_enable(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	if ((argCount == 0 ))
	{
		pifacecad_lcd_pulse_enable();
		printf("\n[HardwareJS Plugin] : pifacecad_lcd_pulse_enable is called ");
		return true;
	}
	return false;
}
static bool zk_colrow2address(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t col;
	uint8_t row;
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 2 ) && NPVARIANT_IS_DOUBLE(args[0]) && NPVARIANT_IS_DOUBLE(args[1]))
	{
		col = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		row = (uint8_t)NPVARIANT_TO_DOUBLE(args[1]);
		zk_outputData = (uint8_t)colrow2address(col, row);
		printf("\n[HardwareJS Plugin] : colrow2address is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_address2col(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t address;
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		address = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		zk_outputData = (uint8_t)address2col(address);
		printf("\n[HardwareJS Plugin] : address2col is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
static bool zk_address2row(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result){
	uint8_t address;
	uint8_t zk_outputData;
	VOID_TO_NPVARIANT(*result);
	if ((argCount == 1 ) && NPVARIANT_IS_DOUBLE(args[0]))
	{
		address = (uint8_t)NPVARIANT_TO_DOUBLE(args[0]);
		zk_outputData = (uint8_t)address2row(address);
		printf("\n[HardwareJS Plugin] : address2row is called ");
		INT32_TO_NPVARIANT(zk_outputData, *result);
		return true;
	}
	return false;
}
// End hardware plugin implementation


static bool zk_getMacAddress(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    char *mac_add;
    mac_add = (char *)obj->browser->memalloc(18);
    const char* mac_add_null = "00:00:00:00:00:00";

    if (!mac_add){
		printf("cannot NPN_MemAlloc");
		STRINGZ_TO_NPVARIANT(mac_add_null, *result);
		return true;
	}

	FILE *fp ;
	fp = fopen("/sys/class/net/eth0/address", "r");
	if(!fp){
		printf("Mac address not found");
		STRINGZ_TO_NPVARIANT(mac_add_null, *result);
		return true;
	}
	else{
		fscanf(fp, "%s", mac_add);
		printf("Mac address is %s", mac_add);
		fclose(fp);
		STRINGZ_TO_NPVARIANT(mac_add, *result);
		return true;
	}
}

static bool zkDebugMessage(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    VOID_TO_NPVARIANT(*result);

    double var;
    if (argCount && NPVARIANT_IS_STRING(args[0])) {
        char* message = NULL;
        NPString statusString = NPVARIANT_TO_STRING(args[0]);
        message = stringMemalloc(obj, statusString);
        STRINGZ_TO_NPVARIANT(message, *result);
        printf("[Zetakey Debug] : %s\n", message);
        return true;
    }
    else if (argCount && NPVARIANT_IS_INT32(args[0])) {
        var = NPVARIANT_TO_INT32(args[0]);
    }
    else if (argCount && NPVARIANT_IS_DOUBLE(args[0])) {
        var = NPVARIANT_TO_DOUBLE(args[0]);
    }
    printf("[Zetakey Debug] : %ld\n", (unsigned long) var);
    DOUBLE_TO_NPVARIANT(var, *result);
    return true;
}


static bool setTestString(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    char* message = NULL;
    if (argCount && NPVARIANT_IS_STRING(args[0]))
    {
        NPString statusString = NPVARIANT_TO_STRING(args[0]);
        message = stringMemalloc(obj, statusString);
        STRINGZ_TO_NPVARIANT(message, *result);
        printf("count:%d, string:%s\n", argCount, message);
        return true;
    }
    return false;
}

static bool getTestString(PluginObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    char *temp = (char *)obj->browser->memalloc(0x100);
    strcpy(temp, "TestSting is Hello, World - Plugin A");
//  obj->browser->geturl(obj->npp, "javascript:toBeCalledByPlugin()", NULL);
	executeScript(obj, "toBeCalledByPlugin()");
	STRINGZ_TO_NPVARIANT(temp, *result);
    return true;
}


static bool pluginHasMethod(NPObject *obj, NPIdentifier name)
{
    for (int i = 0; i < NUM_METHOD_IDENTIFIERS; i++) {
        if (name == pluginMethodIdentifiers[i]) {
//            printf("%s %s %s\n", __FILE__, __FUNCTION__, pluginMethodIdentifierNames[i]);
            return true;
        }
    }
    return false;
}

static bool pluginInvoke(NPObject* header, NPIdentifier name, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    PluginObject* plugin = reinterpret_cast<PluginObject*>(header);

    if (name == pluginMethodIdentifiers[ID_ZK_DEBUG_MSG]) {
//        printf("%s %s %s\n", __FILE__, __FUNCTION__, pluginMethodIdentifierNames[ID_ZK_DEBUG_MSG]);
        return zkDebugMessage(plugin, args, argCount, result);
    }
    if (name == pluginMethodIdentifiers[ID_ZK_SET_STRVALUE]) {
//        printf("%s %s %s\n", __FILE__, __FUNCTION__, pluginMethodIdentifierNames[ID_ZK_SET_STRVALUE]);
        return setTestString(plugin, args, argCount, result);
    }
    if (name == pluginMethodIdentifiers[ID_ZK_GET_STRVALUE]) {
//        printf("%s %s %s\n", __FILE__, __FUNCTION__, pluginMethodIdentifierNames[ID_ZK_GET_STRVALUE]);
        return getTestString(plugin, args, argCount, result);
    }
    if (name == pluginMethodIdentifiers[ID_ZK_GET_MAC_ADDRESS]) {
        return zk_getMacAddress(plugin, args, argCount, result);
    }

    //3. Add ID to functions
    // Hardware.js generated invoke if return

		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_OPEN]){
			return zk_pifacecad_open(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_OPEN_NOINIT]){
			return zk_pifacecad_open_noinit(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_CLOSE]){
			return zk_pifacecad_close(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_INIT]){
			return zk_pifacecad_lcd_init(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_READ_SWITCHES]){
			return zk_pifacecad_read_switches(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_READ_SWITCH]){
			return zk_pifacecad_read_switch(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_WRITE]){
			return zk_pifacecad_lcd_write(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SET_CURSOR]){
			return zk_pifacecad_lcd_set_cursor(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SET_CURSOR_ADDRESS]){
			return zk_pifacecad_lcd_set_cursor_address(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_GET_CURSOR_ADDRESS]){
			return zk_pifacecad_lcd_get_cursor_address(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_CLEAR]){
			return zk_pifacecad_lcd_clear(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_HOME]){
			return zk_pifacecad_lcd_home(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_DISPLAY_ON]){
			return zk_pifacecad_lcd_display_on(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_DISPLAY_OFF]){
			return zk_pifacecad_lcd_display_off(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_BLINK_ON]){
			return zk_pifacecad_lcd_blink_on(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_BLINK_OFF]){
			return zk_pifacecad_lcd_blink_off(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_CURSOR_ON]){
			return zk_pifacecad_lcd_cursor_on(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_CURSOR_OFF]){
			return zk_pifacecad_lcd_cursor_off(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_BACKLIGHT_ON]){
			return zk_pifacecad_lcd_backlight_on(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_BACKLIGHT_OFF]){
			return zk_pifacecad_lcd_backlight_off(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_MOVE_LEFT]){
			return zk_pifacecad_lcd_move_left(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_MOVE_RIGHT]){
			return zk_pifacecad_lcd_move_right(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_LEFT_TO_RIGHT]){
			return zk_pifacecad_lcd_left_to_right(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_RIGHT_TO_LEFT]){
			return zk_pifacecad_lcd_right_to_left(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_AUTOSCROLL_ON]){
			return zk_pifacecad_lcd_autoscroll_on(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_AUTOSCROLL_OFF]){
			return zk_pifacecad_lcd_autoscroll_off(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SEND_COMMAND]){
			return zk_pifacecad_lcd_send_command(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SEND_DATA]){
			return zk_pifacecad_lcd_send_data(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SEND_BYTE]){
			return zk_pifacecad_lcd_send_byte(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SET_RS]){
			return zk_pifacecad_lcd_set_rs(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SET_RW]){
			return zk_pifacecad_lcd_set_rw(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SET_ENABLE]){
			return zk_pifacecad_lcd_set_enable(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_SET_BACKLIGHT]){
			return zk_pifacecad_lcd_set_backlight(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_PIFACECAD_LCD_PULSE_ENABLE]){
			return zk_pifacecad_lcd_pulse_enable(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_COLROW2ADDRESS]){
			return zk_colrow2address(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_ADDRESS2COL]){
			return zk_address2col(plugin, args, argCount, result);
		}
		if (name == pluginMethodIdentifiers[ID_ZK_ADDRESS2ROW]){
			return zk_address2row(plugin, args, argCount, result);
		}

    // End plugin Invoke if return

    return false;
}

static bool pluginHasProperty(NPObject *obj, NPIdentifier name)
{
    for (int i = 0; i < NUM_PROPERTY_IDENTIFIERS; i++) {
        if (name == pluginPropertyIdentifiers[i]) {
            printf("%s %s %s\n", __FILE__, __FUNCTION__, pluginPropertyIdentifierNames[i]);
            return true;
        }
    }
    return false;
}


static bool pluginGetProperty(NPObject* obj, NPIdentifier name, NPVariant* result)
{
    PluginObject* plugin = reinterpret_cast<PluginObject*>(obj);

    printf("%s %s\n", __FILE__, __FUNCTION__);

    if (name == pluginPropertyIdentifiers[ID_PROPERTY_PROPERTY]) {
        static const char* originalString = "property";
        char* buf = static_cast<char*>(plugin->browser->memalloc(strlen(originalString) + 1));
        strcpy(buf, originalString);
        STRINGZ_TO_NPVARIANT(buf, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_EVENT_LOGGING]) {
        BOOLEAN_TO_NPVARIANT(plugin->eventLogging, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_LOG_DESTROY]) {
        BOOLEAN_TO_NPVARIANT(plugin->logDestroy, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_HAS_STREAM]) {
        BOOLEAN_TO_NPVARIANT(plugin->stream != 0, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_RETURN_ERROR_FROM_NEWSTREAM]) {
        BOOLEAN_TO_NPVARIANT(plugin->returnErrorFromNewStream, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_PRIVATE_BROWSING_ENABLED]) {
        NPBool privateBrowsingEnabled = FALSE;
        plugin->browser->getvalue(plugin->npp, NPNVprivateModeBool, &privateBrowsingEnabled);
        BOOLEAN_TO_NPVARIANT(privateBrowsingEnabled, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_CACHED_PRIVATE_BROWSING_ENABLED]) {
        BOOLEAN_TO_NPVARIANT(plugin->cachedPrivateBrowsingMode, *result);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_THROW_EXCEPTION_PROPERTY]) {
        plugin->browser->setexception(obj, "plugin object testThrowExceptionProperty SUCCESS");
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_LAST_SET_WINDOW_ARGUMENTS]) {
        char* buf = static_cast<char*>(plugin->browser->memalloc(256));
        snprintf(buf, 256, "x: %d, y: %d, width: %u, height: %u, clipRect: (%u, %u, %u, %u)", (int)plugin->lastWindow.x, (int)plugin->lastWindow.y, (unsigned)plugin->lastWindow.width, (unsigned)plugin->lastWindow.height,
            plugin->lastWindow.clipRect.left, plugin->lastWindow.clipRect.top, plugin->lastWindow.clipRect.right - plugin->lastWindow.clipRect.left, plugin->lastWindow.clipRect.bottom - plugin->lastWindow.clipRect.top);

        STRINGZ_TO_NPVARIANT(buf, *result);
        return true;
    }

    return false;
}

static bool pluginSetProperty(NPObject* obj, NPIdentifier name, const NPVariant* variant)
{
    PluginObject* plugin = reinterpret_cast<PluginObject*>(obj);

    printf("%s %s\n", __FILE__, __FUNCTION__);

    if (name == pluginPropertyIdentifiers[ID_PROPERTY_EVENT_LOGGING]) {
        plugin->eventLogging = NPVARIANT_TO_BOOLEAN(*variant);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_LOG_DESTROY]) {
        plugin->logDestroy = NPVARIANT_TO_BOOLEAN(*variant);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_RETURN_ERROR_FROM_NEWSTREAM]) {
        plugin->returnErrorFromNewStream = NPVARIANT_TO_BOOLEAN(*variant);
        return true;
    } else if (name == pluginPropertyIdentifiers[ID_PROPERTY_THROW_EXCEPTION_PROPERTY]) {
        plugin->browser->setexception(obj, "plugin object testThrowExceptionProperty SUCCESS");
        return true;
    }

    return false;
}

static bool pluginInvokeDefault(NPObject* obj, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    printf("%s %s\n", __FILE__, __FUNCTION__);

    return true;
}

static void pluginInvalidate(NPObject* header)
{
    printf("%s %s\n", __FILE__, __FUNCTION__);
}

static NPObject *pluginAllocate(NPP npp, NPClass *theClass)
{
    PluginObject* newInstance = (PluginObject*)calloc(1, sizeof(PluginObject));

    printf("%s %s\n", __FILE__, __FUNCTION__);

    newInstance->npp                = npp;
    newInstance->browser            = gBrowser;
    newInstance->eventLogging       = FALSE;

    newInstance->onStreamLoad       = 0;
    newInstance->onStreamDestroy    = 0;
    newInstance->onDestroy          = 0;
    newInstance->onURLNotify        = 0;
    newInstance->onSetWindow        = 0;

    newInstance->logDestroy                 = FALSE;
    newInstance->logSetWindow               = FALSE;
    newInstance->returnErrorFromNewStream   = FALSE;
    newInstance->stream =                   0;

    newInstance->testGetURLOnDestroy                = FALSE;
    newInstance->testDocumentOpenInDestroyStream    = FALSE;
    newInstance->testWindowOpen                     = FALSE;
    newInstance->testKeyboardFocusForPlugins        = FALSE;

    newInstance->browser->getstringidentifiers(pluginPropertyIdentifierNames, NUM_PROPERTY_IDENTIFIERS, pluginPropertyIdentifiers);
    newInstance->browser->getstringidentifiers(pluginMethodIdentifierNames, NUM_METHOD_IDENTIFIERS, pluginMethodIdentifiers);

    return (NPObject*)newInstance;
}

static void pluginDeallocate(NPObject* header)
{
    PluginObject* plugin = reinterpret_cast<PluginObject*>(header);

    printf("%s %s\n", __FILE__, __FUNCTION__);

    free(plugin);
}

static NPClass npClass = {
    NP_CLASS_STRUCT_VERSION,
    pluginAllocate,
    pluginDeallocate,
    pluginInvalidate,
    pluginHasMethod,
    pluginInvoke,
    pluginInvokeDefault,
    pluginHasProperty,
    pluginGetProperty,
    pluginSetProperty,
};

static void log(NPP instance, const char* format, ...)
{
    PluginObject*   plugin          = static_cast<PluginObject*>(instance->pdata);
    char            message[2048]   = "PLUGIN: ";

    va_list args;
    va_start(args, format);

    vsprintf(message + strlen(message), format, args);
    va_end(args);

    NPObject* windowObject = 0;
    NPError error = plugin->browser->getvalue(instance, NPNVWindowNPObject, &windowObject);
    if (error != NPERR_NO_ERROR) {
        fprintf(stderr, "Failed to retrieve window object while logging: %s\n", message);
        return;
    }

    NPVariant consoleVariant;
    if (!plugin->browser->getproperty(instance, windowObject, plugin->browser->getstringidentifier("console"), &consoleVariant)) {
        fprintf(stderr, "Failed to retrieve console object while logging: %s\n", message);
        plugin->browser->releaseobject(windowObject);
        return;
    }

    NPObject* consoleObject = NPVARIANT_TO_OBJECT(consoleVariant);

    NPVariant messageVariant;
    STRINGZ_TO_NPVARIANT(message, messageVariant);

    NPVariant result;
    if (!plugin->browser->invoke(instance, consoleObject, plugin->browser->getstringidentifier("log"), &messageVariant, 1, &result)) {
        fprintf(stderr, "Failed to invoke console.log while logging: %s\n", message);
        plugin->browser->releaseobject(consoleObject);
        plugin->browser->releaseobject(windowObject);
        return;
    }
    plugin->browser->releasevariantvalue(&result);
    plugin->browser->releaseobject(consoleObject);
    plugin->browser->releaseobject(windowObject);
}

static NPError
zk_plugin_new_instance(NPMIMEType mimetype, NPP instance, uint16_t mode, int16_t argc, char *argn[], char *argv[], NPSavedData *savedData)
{
    printf("%s %s\n", __FILE__, __FUNCTION__);
    printf("    ");
    for (int i = 0; i < argc; i++)
        printf("%s='%s' ", argn[i], argv[i]);
    printf("\n");

    if (gBrowser->version >= 14) {
        PluginObject* obj   = (PluginObject*)gBrowser->createobject(instance, &npClass);
        instance->pdata     = obj;

        for (int i = 0; i < argc; i++) {
            if (strcasecmp(argn[i], "onstreamload") == 0 && !obj->onStreamLoad)
                obj->onStreamLoad = strdup(argv[i]);
            else if (strcasecmp(argn[i], "onStreamDestroy") == 0 && !obj->onStreamDestroy)
                obj->onStreamDestroy = strdup(argv[i]);
            else if (strcasecmp(argn[i], "onURLNotify") == 0 && !obj->onURLNotify)
                obj->onURLNotify = strdup(argv[i]);
            else if (strcasecmp(argn[i], "src") == 0)
                obj->returnErrorFromNewStream = TRUE;
            else if (strcasecmp(argn[i], "logfirstsetwindow") == 0)
                obj->logSetWindow = TRUE;
        }
    }
    return NPERR_NO_ERROR;
}

static NPError
zk_plugin_destroy_instance(NPP instance, NPSavedData **save)
{
    PluginObject* obj = static_cast<PluginObject*>(instance->pdata);

    printf("%s %s\n", __FILE__, __FUNCTION__);

    if (obj) {
        if (obj->onStreamLoad)
            free(obj->onStreamLoad);

        if (obj->onStreamDestroy)
            free(obj->onStreamDestroy);

        if (obj->onURLNotify)
            free(obj->onURLNotify);

        if (obj->logDestroy)
            log(instance, "NPP_Destroy");

        obj->browser->releaseobject(&obj->header);
    }
    return NPERR_NO_ERROR;
}

static NPError
zk_plugin_set_window(NPP instance, NPWindow *window)
{
    PluginObject* obj = static_cast<PluginObject*>(instance->pdata);

    printf("%s %s\n", __FILE__, __FUNCTION__);

    if (obj) {
        if (obj->logSetWindow) {
            log(instance, "NPP_SetWindow: %d %d", (int)window->width, (int)window->height);
            obj->logSetWindow = false;
        }
    }
    return NPERR_NO_ERROR;
}

static NPError
zk_plugin_new_stream(NPP instance, NPMIMEType type, NPStream *stream, NPBool seekable, uint16* stype)
{
    PluginObject* obj = static_cast<PluginObject*>(instance->pdata);

    printf("%s %s\n", __FILE__, __FUNCTION__);

    obj->stream = stream;
    *stype = NP_ASFILEONLY;

    if (obj->returnErrorFromNewStream)
        return NPERR_GENERIC_ERROR;
#if 0 // FLEE !!!
    if (obj->browser->version >= NPVERS_HAS_RESPONSE_HEADERS)
        notifyStream(obj, stream->url, stream->headers);
#endif
    if (obj->onStreamLoad)
        executeScript(obj, obj->onStreamLoad);

    return NPERR_NO_ERROR;
}

static NPError
zk_plugin_destroy_stream(NPP instance, NPStream *stream, NPError reason)
{
    PluginObject* obj = (PluginObject*)instance->pdata;

    if (obj->onStreamDestroy)
        executeScript(obj, obj->onStreamDestroy);

    return NPERR_NO_ERROR;
}

static void
zk_plugin_stream_as_file(NPP instance, NPStream *stream, const char* fname)
{
}

static int32
zk_plugin_write_ready(NPP instance, NPStream *stream)
{
    return 0;
}

static int32
zk_plugin_write(NPP instance, NPStream *stream, int32_t offset, int32_t len, void *buffer)
{
    return 0;
}

static void
zk_plugin_print(NPP instance, NPPrint* platformPrint)
{
}

static int16_t
zk_plugin_handle_event(NPP instance, void* event)
{
    PluginObject* obj = static_cast<PluginObject*>(instance->pdata);

    if (!obj->eventLogging)
        return 0;

    return 0;
}

static void
zk_plugin_url_notify(NPP instance, const char* url, NPReason reason, void* notifyData)
{
    PluginObject* obj = static_cast<PluginObject*>(instance->pdata);

    if (obj->onURLNotify)
        executeScript(obj, obj->onURLNotify);
#if 0 // FLEE !!!
    handleCallback(obj, url, reason, notifyData);
#endif
}

static NPError
zk_plugin_get_value(NPP instance, NPPVariable variable, void *value)
{
    NPError err = NPERR_NO_ERROR;

    printf("%s %s variable=%d\n", __FILE__, __FUNCTION__, variable);

    switch (variable) {
        case NPPVpluginNameString:
            *((const char **)value) = "pifacecad";
            break;
        case NPPVpluginDescriptionString:
            *((const char **)value) = "Pifacecad Plugin";
            break;
        case NPPVpluginNeedsXEmbed:
            *((NPBool *)value) = TRUE;
            break;
        case NPPVpluginScriptableIID:
        case NPPVpluginScriptableInstance:
        case NPPVpluginScriptableNPObject:
            err = NPERR_GENERIC_ERROR;
            break;
        default:
            fprintf(stderr, "Unhandled variable\n");
            err = NPERR_GENERIC_ERROR;
            break;
    }
    if (variable == NPPVpluginScriptableNPObject) {
        void **v = (void **)value;
        PluginObject* obj = static_cast<PluginObject*>(instance->pdata);
        obj->browser->retainobject((NPObject *)obj);
        *v = obj;
        err = NPERR_NO_ERROR;
    }

    return err;
}

static NPError
zk_plugin_set_value(NPP instance, NPNVariable variable, void *value)
{
    printf("%s %s\n", __FILE__, __FUNCTION__);

    return NPERR_NO_ERROR;
}

extern "C" {
    NPError NP_Initialize (NPNetscapeFuncs *aMozillaVTable, NPPluginFuncs *aPluginVTable);
    char*   NP_GetMIMEDescription (void);
    NPError NP_GetValue (void *future, NPPVariable variable, void *value);
    NPError NP_Shutdown (void);
}

char *
NP_GetMIMEDescription(void)
{
    printf("%s %s A\n", __FILE__, __FUNCTION__);

    return (char*)"application/x-zetakey-pifacecad:pifacecad:Pifacecad Plugin";
}

NPError
NP_Initialize (NPNetscapeFuncs *aMozillaVTable, NPPluginFuncs *aPluginVTable)
{
    printf("%s %s aMozillaVTable=%p aPluginVTable=%p\n", __FILE__, __FUNCTION__, aMozillaVTable, aPluginVTable);

    if (aMozillaVTable == NULL || aPluginVTable == NULL)
        return NPERR_INVALID_FUNCTABLE_ERROR;

    if ((aMozillaVTable->version >> 8) > NP_VERSION_MAJOR)
        return NPERR_INCOMPATIBLE_VERSION_ERROR;

    if (aMozillaVTable->size < sizeof (NPNetscapeFuncs))
        return NPERR_INVALID_FUNCTABLE_ERROR;

    if (aPluginVTable->size < sizeof (NPPluginFuncs))
        return NPERR_INVALID_FUNCTABLE_ERROR;

    gBrowser = aMozillaVTable;

    aPluginVTable->size           = sizeof (NPPluginFuncs);
    aPluginVTable->version        = (NP_VERSION_MAJOR << 8) + NP_VERSION_MINOR;
    aPluginVTable->newp           = zk_plugin_new_instance;
    aPluginVTable->destroy        = zk_plugin_destroy_instance;
    aPluginVTable->setwindow      = zk_plugin_set_window;
    aPluginVTable->newstream      = zk_plugin_new_stream;
    aPluginVTable->destroystream  = zk_plugin_destroy_stream;
    aPluginVTable->asfile         = zk_plugin_stream_as_file;
    aPluginVTable->writeready     = zk_plugin_write_ready;
    aPluginVTable->write          = zk_plugin_write;
    aPluginVTable->print          = zk_plugin_print;
    aPluginVTable->event          = zk_plugin_handle_event;
    aPluginVTable->urlnotify      = zk_plugin_url_notify;
    aPluginVTable->javaClass      = NULL;
    aPluginVTable->getvalue       = zk_plugin_get_value;
    aPluginVTable->setvalue       = zk_plugin_set_value;

    return NPERR_NO_ERROR;
}

NPError
NP_Shutdown(void)
{
    return NPERR_NO_ERROR;
}

NPError
NP_GetValue(void *future, NPPVariable variable, void *value)
{
    return zk_plugin_get_value(NULL, variable, value);
}
