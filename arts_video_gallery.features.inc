<?php
/**
 * @file
 * arts_video_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function arts_video_gallery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function arts_video_gallery_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function arts_video_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: widescreen_preview.
  $styles['widescreen_preview'] = array(
    'name' => 'widescreen_preview',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '290',
          'height' => '163',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function arts_video_gallery_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Create a <em>Video</em> to add items to your video gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/*
 * hook_url_inbound_alter
 * Gary
 */
function arts_video_gallery_url_inbound_alter(&$path, $original_path, $path_language) {
	/* 
		On mysite.com/video/video_name, we turn off the transcript field. 
		We add jquery menu next to the video on the top. 
		We keep the menu link 'first time enrolment' open on page load.
	*/
	if(preg_match('|^video/(.+)?|', $original_path, $matches)) {
		_add_javascript('arts_video_gallery', 'arts_video_gallery.js');
	}
	elseif(preg_match('|^video/?|', $original_path, $matches)) {
		_add_javascript('arts_video_gallery', 'arts_video_gallery.js');
	}
	elseif(preg_match('|^arts-student-centre/commencing/ba-study-area-videos/?|', $original_path, $matches)) {
		// Specific to arts.unimelb.edu.au
		_add_javascript('arts_video_gallery', 'arts_video_gallery.js');
	}
}

function _add_javascript($module_name, $script_name) {
  $scripts = drupal_add_js();
  $script_path = drupal_get_path('module', $module_name) . "/js/$script_name";

  if(!isset($scripts[$script_path])) {
  	drupal_add_js($script_path);
  }
}
