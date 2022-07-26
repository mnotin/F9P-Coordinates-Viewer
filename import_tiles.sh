#!/bin/sh

if [ $# -eq 0 ]; then
    echo "No argument supplied. Please specify the directory containing the tiles."
else
    source_directory=$1
    declare -i nb_of_tiles=`find $source_directory -name "*.png" -type f | wc -l`
    declare -i tiles_parsed=1
    current_dir=`pwd`

    mkdir -p Offline_tiles

    if [ "${source_directory: -1}" == "/" ]; then
	source_directory=${source_directory%?} # Remove the '/' at the end of the folder's path
    fi

    cd $source_directory

    for zoom_level_dir in $source_directory/*; do
	if [ -d "$zoom_level_dir" ]; then
	    for row_tile_dir in $zoom_level_dir/*; do
		if [ -d "$row_tile_dir" ]; then
		    for column_tile_file in $row_tile_dir/*; do
			if [ -f $column_tile_file ]; then
			    declare -i progress=$(( (tiles_parsed * 100) / nb_of_tiles ))
			    echo "[$progress%] Processing tile $column_tile_file"
			    
			    zoom_level=`realpath --relative-to=. $column_tile_file | cut -d / -f 1`
			    y=`realpath --relative-to=. $column_tile_file | cut -d / -f 3 | cut -d . -f 1`
			    x=`realpath --relative-to=. $column_tile_file | cut -d / -f 2`
			    extension=`realpath --relative-to=. $column_tile_file | cut -d / -f 3 | cut -d . -f 2`

			    cp "$column_tile_file" "$current_dir/Offline_tiles/osm_100-l-1-$zoom_level-$x-$y.$extension"
			    tiles_parsed=$(( tiles_parsed + 1 ))
			fi
		    done
		fi
	    done
	fi
    done
fi
