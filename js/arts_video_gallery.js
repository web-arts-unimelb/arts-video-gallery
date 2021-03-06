(function ($) {
  Drupal.behaviors.arts_video_gallery = {
    attach:function(context, settings) {
			jQuery('ul.jquerymenu').once('arts_video_gallery_func', function(){
				_arts_active_menu_link();
				_arts_set_body_with_based_on_video();
				_arts_wrap_title();
			});
		}
	}

	function _arts_active_menu_link() {
		var text_link = 'BA study area videos';
		var selector = "ul.jquerymenu a:contains('" + text_link + "')";
  	jQuery(selector).parent().parents('li').removeClass('closed').addClass('open');
    jQuery(selector).parent().parents('li').children('span').removeClass('closed').addClass('open');
    jQuery(selector).addClass('active');
  }

	function _arts_set_body_with_based_on_video() {
		var width = jQuery('.field-name-field-video-video.arts_video_gallery').width();
		jQuery('.field-name-body.arts_video_gallery').width(width);
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
