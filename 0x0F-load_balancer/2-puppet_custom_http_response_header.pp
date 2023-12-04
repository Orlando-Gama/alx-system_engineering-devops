# File: 2-puppet_custom_http_response_header.pp

# Ensure Nginx is installed
package { 'nginx':
  ensure => installed,
}

# Define the custom HTTP header and its value
$custom_header_name = 'X-Served-By'
$custom_header_value = $::hostname

# Configure Nginx with the custom header
file { '/etc/nginx/sites-available/default':
  ensure  => file,
  replace => true,
  content => template('nginx/default.erb'),
  notify  => Service['nginx'],
}

# Ensure Nginx service is running and enabled
service { 'nginx':
  ensure  => running,
  enable  => true,
  require => File['/etc/nginx/sites-available/default'],
}

