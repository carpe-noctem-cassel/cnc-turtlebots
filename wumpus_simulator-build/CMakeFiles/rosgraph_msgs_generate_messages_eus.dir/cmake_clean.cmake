file(REMOVE_RECURSE
  "wumpus_simulator_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/rosgraph_msgs_generate_messages_eus.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()