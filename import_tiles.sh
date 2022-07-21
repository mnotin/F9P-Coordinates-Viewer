#!/bin/sh

from_directory=$1
to_directory=$2

cd $from_directory

for zoom_level_dir in $from_directory/*; do
    if [ -d "$zoom_level_dir" ]; then
	for row_tile_dir in $zoom_level_dir/*; do
	    if [ -d "$row_tile_dir" ]; then
		for column_tile_file in $row_tile_dir/*; do
		    if [ -f $column_tile_file ]; then
			echo "$column_tile_file"

			zoom_level=`echo $column_tile_file | cut -d / -f 6`
			y=`echo $column_tile_file | cut -d / -f 8 | cut -d . -f 1`
			x=`echo $column_tile_file | cut -d / -f 7`
			extension=`echo $column_tile_file | cut -d / -f 8 | cut -d . -f 2`

			cp $column_tile_file "${to_directory}/osm_100-l-3-${zoom_level}-${x}-${y}.${extension}"
		    fi
		done
	    fi
	done
    fi
done
