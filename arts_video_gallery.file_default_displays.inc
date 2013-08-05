<?php
/**
 * @file
 * arts_video_gallery.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function arts_video_gallery_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_small__media_youtube_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'widescreen_preview',
  );
  $export['video__media_small__media_youtube_image'] = $file_display;

  return $export;
}
