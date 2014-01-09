(function ($) {
  Drupal.behaviors.arts_video_gallery = {
    attach:function(context, settings) {
			jQuery('ul.jquerymenu').once('jquerymenu_func', function(){
				_arts_active_menu_link();
				_arts_set_body_with_based_on_video();
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

}(jQuery));
