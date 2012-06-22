<?php


function course_source_api_admin_settings() {
  $form = array();
  $form['course_source_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Course Source LMS Endpoint'),
    '#description' => t('Enter the URL for accessing the Course Source web service.'),
    '#default_value' => variable_get('course_source_endpoint', 'http://beta.course-source.net/ws/AutoLogin-rpc.php'),
  );
  $form['course_source_api_version'] = array(
    '#type' => 'radios',
    '#title' => t('API Version'),
    '#options' => array('rpc' => 'XMLRPC', 'json.1' => 'JSONRPC v1'),
    '#default_value' => variable_get('course_source_api_version', 'json.1'),
  );
  $form['course_source_siteid'] = array(
    '#type' => 'textfield',
    '#title' => t('Course Source SiteID'),
    '#description' => t('Enter your Course Source Site ID'),
    '#default_value' => variable_get('course_source_siteid', ''),
  );
  $form['course_source_sitekey'] = array(
    '#type' => 'textfield',
    '#title' => t('Course Source SiteKey'),
    '#description' => t('Enter your secret Course Source Site Key'),
    '#default_value' => variable_get('course_source_sitekey', ''),
  );
  $form['course_source_user_sync'] = array(
    '#type' => 'checkbox',
    '#title' => t('Synchronise user accounts'),
    '#description' => t('Select this box to automatically create user accounts on Course Source when the user is added to Drupal.'),
    '#default_value' => variable_get('course_source_user_sync', TRUE),
  );
  $form['course_source_admin_change_username'] = array(
  	'#type' => 'checkbox',
   	'#title' => t('Allow admin to change own username'),
		'#description' => t('When using user Synchronisation a username must be changed in the master system. Select this to allow UID 1 to be able to change their Drupal username.'),
		'#default_value' => variable_get('course_source_admin_change_username', TRUE),
  ),
  $form['course_source_default_group_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Course Source default group name'),
    '#description' => t('If user synchronisation is enabled, enter the default group name to assign users to.'),
    '#default_value' => variable_get('course_source_default_group_name', 'Students'),
  );
  $form['course_source_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Debug mode'),
    '#description' => t('Save debugging information into Drupal log when making API calls. If this is not selected only error messages will be logged.'),
    '#default_value' => variable_get('course_source_debug', FALSE),
  );
  return system_settings_form($form);
}


function course_source_api_admin_mappings() {
  $form = array();
  if (variable_get('course_source_user_sync', TRUE)) {
    $field_options = array();
    foreach (field_info_fields() as $fieldname => $field) {
      if (isset($field['bundles']['user']) && $field['module'] == 'text') {
        $field_options[$fieldname] = $fieldname;
      }
    }
    $field_options = array_merge(array(0 => '-- none --'), $field_options);
    $form['course_source_mapping_firstname'] = array(
      '#type' => 'select',
      '#title' => t('First name'),
      '#description' => t('Select the user field to map to the Course Source FirstName field.'),
      '#options' => $field_options,
      '#default_value' => variable_get('course_source_mapping_firstname', 0),
    );
    $form['course_source_mapping_lastname'] = array(
      '#type' => 'select',
      '#title' => t('Last name'),
      '#description' => t('Select the user field to map to the Course Source LastName field.'),
      '#options' => $field_options,
      '#default_value' => variable_get('course_source_mapping_lastname', 0),
    );
    $form['course_source_mapping_groupname'] = array(
      '#type' => 'select',
      '#title' => t('Group name'),
      '#description' => t('Select the user field to map to the Course Source GroupName field.'),
      '#options' => $field_options,
      '#default_value' => variable_get('course_source_mapping_groupname', 0),
    );
    return system_settings_form($form);
  } else {
    $form['no_mappings'] = array(
      '#type' => 'markup',
      '#markup' => t('You have not enabled User Synchronisation so you do not need to set up any mappings.'),
    );
  }
  return $form;
}


























