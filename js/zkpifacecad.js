/*
 ************************************************************************
 * zk_pifacecad.js
 *  Javascript Pifacecad plugin interface for Raspberry Pi
 *  It is part of <hw.js> from Zetakey
 *  Author: Jack Wong <jack.wong@zetakey.com>
 *	Copyright (c) 2015 Zetakey Solutions Limited
 ************************************************************************
 */

var zkpifacecad = (function () {
  //private
  var initialized,
      pluginObj;

  var emulatedPlugin = {   // Hardware.js generated emulated plugin functions

		pifacecad_open: function(){
			console.log("pifacecad_open is called. ");
			return 0;
		},
		pifacecad_open_noinit: function(){
			console.log("pifacecad_open_noinit is called. ");
			return 0;
		},
		pifacecad_close: function(){
			console.log("pifacecad_close is called. ");
		},
		pifacecad_lcd_init: function(){
			console.log("pifacecad_lcd_init is called. ");
		},
		pifacecad_read_switches: function(){
			console.log("pifacecad_read_switches is called. ");
			return 0;
		},
		pifacecad_read_switch: function(arg0){
			console.log("pifacecad_read_switch is called. "+"arg0="+arg0);
			return 0;
		},
		pifacecad_lcd_write: function(arg0){
			console.log("pifacecad_lcd_write is called. "+"arg0="+arg0);
			return 0;
		},
		pifacecad_lcd_set_cursor: function(arg0, arg1){
			console.log("pifacecad_lcd_set_cursor is called. "+"arg0="+arg0+","+"arg1="+arg1);
			return 0;
		},
		pifacecad_lcd_set_cursor_address: function(arg0){
			console.log("pifacecad_lcd_set_cursor_address is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_get_cursor_address: function(){
			console.log("pifacecad_lcd_get_cursor_address is called. ");
			return 0;
		},
		pifacecad_lcd_clear: function(){
			console.log("pifacecad_lcd_clear is called. ");
		},
		pifacecad_lcd_home: function(){
			console.log("pifacecad_lcd_home is called. ");
		},
		pifacecad_lcd_display_on: function(){
			console.log("pifacecad_lcd_display_on is called. ");
		},
		pifacecad_lcd_display_off: function(){
			console.log("pifacecad_lcd_display_off is called. ");
		},
		pifacecad_lcd_blink_on: function(){
			console.log("pifacecad_lcd_blink_on is called. ");
		},
		pifacecad_lcd_blink_off: function(){
			console.log("pifacecad_lcd_blink_off is called. ");
		},
		pifacecad_lcd_cursor_on: function(){
			console.log("pifacecad_lcd_cursor_on is called. ");
		},
		pifacecad_lcd_cursor_off: function(){
			console.log("pifacecad_lcd_cursor_off is called. ");
		},
		pifacecad_lcd_backlight_on: function(){
			console.log("pifacecad_lcd_backlight_on is called. ");
		},
		pifacecad_lcd_backlight_off: function(){
			console.log("pifacecad_lcd_backlight_off is called. ");
		},
		pifacecad_lcd_move_left: function(){
			console.log("pifacecad_lcd_move_left is called. ");
		},
		pifacecad_lcd_move_right: function(){
			console.log("pifacecad_lcd_move_right is called. ");
		},
		pifacecad_lcd_left_to_right: function(){
			console.log("pifacecad_lcd_left_to_right is called. ");
		},
		pifacecad_lcd_right_to_left: function(){
			console.log("pifacecad_lcd_right_to_left is called. ");
		},
		pifacecad_lcd_autoscroll_on: function(){
			console.log("pifacecad_lcd_autoscroll_on is called. ");
		},
		pifacecad_lcd_autoscroll_off: function(){
			console.log("pifacecad_lcd_autoscroll_off is called. ");
		},
		pifacecad_lcd_send_command: function(arg0){
			console.log("pifacecad_lcd_send_command is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_send_data: function(arg0){
			console.log("pifacecad_lcd_send_data is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_send_byte: function(arg0){
			console.log("pifacecad_lcd_send_byte is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_set_rs: function(arg0){
			console.log("pifacecad_lcd_set_rs is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_set_rw: function(arg0){
			console.log("pifacecad_lcd_set_rw is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_set_enable: function(arg0){
			console.log("pifacecad_lcd_set_enable is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_set_backlight: function(arg0){
			console.log("pifacecad_lcd_set_backlight is called. "+"arg0="+arg0);
		},
		pifacecad_lcd_pulse_enable: function(){
			console.log("pifacecad_lcd_pulse_enable is called. ");
		},
		colrow2address: function(arg0, arg1){
			console.log("colrow2address is called. "+"arg0="+arg0+","+"arg1="+arg1);
			return 0;
		},
		address2col: function(arg0){
			console.log("address2col is called. "+"arg0="+arg0);
			return 0;
		},
		address2row: function(arg0){
			console.log("address2row is called. "+"arg0="+arg0);
			return 0;
		},
    // End emulated plugins
  }

  var initPluginObject = function(){
    var str = "";

    pluginObj = document.createElement("Object");
    pluginObj.setAttribute("type", "application/x-zetakey-pifacecad");
    pluginObj.setAttribute("width", "0");
    pluginObj.setAttribute("height", "0");
    document.body.appendChild(pluginObj);
    console.log("Initialize Plugin Object\n");


    if (! pluginObj.setTestString) {
        str = "no plugin for 'application/x-zetakey-pifacecad'.\n";
        console.log(str);
        return false;
    } else {
        var res1        = pluginObj.setTestString("Zetakey Plugin test");
        var testString  = pluginObj.getTestString();
        str += "get string : " + testString + "<br>";
        str += "set string : " + res1 + "<br>";
        console.log(str);
        return true;
    }
    console.log(str);
  };

  return {
//public
    plugin: function(){
      if(!initialized){
        if( !initPluginObject() ){
          pluginObj = emulatedPlugin;
			str = "emulated Plugin is loaded\n";
			console.log(str);
        }
        initialized = true;
      }
      return pluginObj;
    },

// hardware value
// Hardware.js generated defined value
		LCD_CLEARDISPLAY: 0x01,
		LCD_RETURNHOME: 0x02,
		LCD_ENTRYMODESET: 0x04,
		LCD_DISPLAYCONTROL: 0x08,
		LCD_CURSORSHIFT: 0x10,
		LCD_FUNCTIONSET: 0x20,
		LCD_SETCGRAMADDR: 0x40,
		LCD_SETDDRAMADDR: 0x80,
		LCD_NEWLINE: 0xC0,

  }

})()
