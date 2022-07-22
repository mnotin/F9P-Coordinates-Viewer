#!/bin/sh

source_directory=$1
target_directory=$2
declare -i nb_of_tiles=`find $source_directory -name "*.png" -type f | wc -l`

declare -i tiles_parsed=1

for zoom_level_dir in $source_directory/*; do
    if [ -d "$zoom_level_dir" ]; then
	for row_tile_dir in $zoom_level_dir/*; do
	    if [ -d "$row_tile_dir" ]; then
		for column_tile_file in $row_tile_dir/*; do
		    if [ -f $column_tile_file ]; then
			declare -i progress=$(( (tiles_parsed * 100) / nb_of_tiles ))
			echo "Processing tile $column_tile_file ... [$progress%]"  

			zoom_level=`echo $column_tile_file | cut -d / -f 6`
			y=`echo $column_tile_file | cut -d / -f 8 | cut -d . -f 1`
			x=`echo $column_tile_file | cut -d / -f 7`
			extension=`echo $column_tile_file | cut -d / -f 8 | cut -d . -f 2`

			cp "$column_tile_file" "$target_directory/osm_100-l-3-$zoom_level-$x-$y.$extension"
			tiles_parsed=$(( tiles_parsed + 1 ))
		    fi
		done
	    fi
	done
    fi
done
