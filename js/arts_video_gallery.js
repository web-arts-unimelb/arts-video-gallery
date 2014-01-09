(function ($) {
  Drupal.behaviors.arts_video_gallery = {
    attach:function(context, settings) {
			jQuery('ul.jquerymenu').once('jquerymenu_func', function(){
				jQuery("ul.jquerymenu a:contains('First time enrolment')").parent().parents('li').removeClass('closed').addClass('open');

				jQuery("ul.jquerymenu a:contains('First time enrolment')").parent().parents('li').children('span').removeClass('closed').addClass('open');

				jQuery("ul.jquerymenu a:contains('First time enrolment')").addClass('active');	
			});
		}
	}
}(jQuery));
