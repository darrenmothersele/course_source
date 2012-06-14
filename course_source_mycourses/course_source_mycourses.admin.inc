<?php

function course_source_mycourses_settings() {
	$form = array();
	
	$form['course_source_mycourses_performance'] = array(
		'#type' => 'fieldset',
	  '#title' => t('Performance'),
	  '#description' => t('Configure caching settings for the MyCourse page. Caching is enabled by 
	    default as it greatly reduces the number of calls that are required to the API.'),
	);
	$form['course_source_mycourses_performance']['course_source_mycourses_cache'] = array(
		'#type' => 'checkbox',
		'#title' => t('Allow caching of MyCourse data to improve performance.'),
		'#default_value' => variable_get('course_source_mycourses_cache', TRUE),
	);
	$form['course_source_mycourses_performance']['course_source_mycourses_cache_clear'] = array(
		'#type' => 'checkbox',
		'#title' => t('Clear the course cache after closing tutorial modal window.'),
		'#description' => t('If this option is selected any course data for a user that has been cached 
		  is updated when the user closes a modal popup, so that the reported progress is updated.'),
		'#default_value' => variable_get('course_source_mycourses_cache_clear', TRUE),
	);
	
	$form['course_source_tutorial_modal'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#title' => t('Tutorial modal window settings'),
	);
	$form['course_source_tutorial_modal']['course_source_tutorial_modal_type'] = array(
		'#type' => 'select',
		'#title' => t('Type'),
		'#description' => t('Select the method for calculating the size of the tutorial modal popup. 
		  <em>Fixed</em> allows you to specify a fixed size in pixels, whereas <em>scale</em> allows you to specify a 
		  ratio of the current visible window. For example 1 = 100% width, 0.75 = 75% width, etc.'),
		'#options' => array('scale' => 'Scale', 'fixed' => 'Fixed'),
		'#default_value' => variable_get('course_source_tutorial_modal_type', 'scale'),
	);
  $form['course_source_tutorial_modal']['course_source_tutorial_modal_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 5,
    '#description' => t('Enter the required <strong>width</strong> of the modal popup. If you selected <em>scale</em> as the modal type 
      this must be a number between 0 and 1, for example, to take half the available screen width enter 0.5. 
      If you selected <em>fixed</em> as the modal type then enter a size in pixels (but ommit the px, eg 500).'),
    '#default_value' => variable_get('course_source_tutorial_modal_width', 0.95),
  );
  $form['course_source_tutorial_modal']['course_source_tutorial_modal_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 5,
    '#description' => t('Enter the required <strong>height</strong> of the modal popup. If you selected <em>scale</em> as the modal type 
      this must be a number between 0 and 1, for example, to take half the available screen height enter 0.5. 
      If you selected <em>fixed</em> as the modal type then enter a size in pixels (but ommit the px, eg 500).'),
    '#default_value' => variable_get('course_source_tutorial_modal_height', 0.95),
  );
	
  return system_settings_form($form);
}