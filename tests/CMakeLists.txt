
foreach(app  tip5)
	add_executable(${app} ${app}.cpp)
	target_link_libraries(${app} PRIVATE qb1t6)
	add_test(NAME ${app} COMMAND ${app})
endforeach()
