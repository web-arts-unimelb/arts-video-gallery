(function ($) {
  Drupal.behaviors.arts_video_gallery = {
    attach:function(context, settings) {
      jQuery('ul.jquerymenu').once('jquerymenu_func', function(){
   			_arts_wrap_title();    
      });
    }
  }

	function _arts_wrap_title() {
    // Pick on image
    var img_selector = ".arts_video_gallery_wrap_img img:eq(0)";
    var img_width = jQuery(img_selector).width();

    var title_selector = ".arts_video_gallery_wrap_title a";
    jQuery(title_selector).width(img_width);
    jQuery(title_selector).css({ display: "block" });
  }

}(jQuery));

