<?php


function course_source_admin_list_courses_page($cid = NULL) {
  if ($cid == NULL) {
    $table = array(
      'header' => array('CourseID', 'CourseTitle'),
      'rows' => array(),
    );
    $courses = course_source_api_get_courses();
    foreach ($courses as $course) {
      $table['rows'][] = array(
        l($course['CourseID'], 'admin/config/services/course-source/courses/'. $course['CourseID']), 
        $course['CourseTitle'],
      );
    }
    return theme('table', $table);
  } else {
    $table = array(
      'header' => array('PriceTypeID', 'Duration', 'DurationDescription'),
      'rows' => array(),
    );
    $durations = course_source_api_call('getDurations', array($cid));
    foreach ($durations as $item) {
      $table['rows'][] = array($item['PriceTypeID'], $item['Duration'], $item['DurationDescription']);
    }
    return theme('table', $table);
  }
}

function _course_source_admin_enrol_form() {
  $course_options = array();
  foreach (course_source_api_get_courses() as $course) {
    $course_options[$course['CourseID']] = $course['CourseTitle'];
  }
  $user_options = _course_source_api_get_users();
  $form = array();
  $form['course_id'] = array(
    '#type' => 'select',
    '#title' => 'Course',
    '#options' => $course_options,
  );
  $form['user_id'] = array(
    '#type' => 'select',
    '#title' => 'User',
    '#options' => $user_options,
  );
  $form['price_id'] = array(
    '#type' => 'textfield',
    '#title' => 'Price ID',
  );
  $form['start_date'] = array(
    '#type' => 'textfield',
    '#title' => 'Start Date',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Enrol user',
  );
  return $form;
}
function _course_source_admin_enrol_form_submit($form, &$form_state) {
  $result = course_source_api_call('enrolUser', array(
    $form_state['values']['user_id'], 
    $form_state['values']['course_id'], 
    $form_state['values']['price_id'], 
    $form_state['values']['start_date'],
  ));
  if ($result) { 
    drupal_set_message("Enrolled user {$form_state['values']['user_id']} on course {$form_state['values']['course_id']}");
  }
}
