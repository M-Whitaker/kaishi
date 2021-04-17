#! /usr/bin/python3

"""
A file...
"""

import json
import logging
import os

# The location of the vendor folder relative from the current script.
import subprocess

RELATIVE_VENDOR_FOLDER_LOCATION = ".."


def __read_json(filepath: str):
    """
    Reads json file
    """
    logging.debug("reading json: %s" % filepath)
    with open(filepath, 'r') as file:
        return json.load(file)


class Vendor:
    """
    Vendor...
    """

    def __init__(self, name: str, folder: str, patches: dict, relative_path: str):
        self.m_name = name
        self.m_folder = folder
        self.patches = patches
        self.relative_path = relative_path

    def apply_patches(self):
        """
        """
        for patch in self.patches:
            logging.info("Applying patches...")
            patch_path = os.path.join(self.relative_path, patch['fileName'])
            os.chdir(os.path.join(self.relative_path, self.m_folder))
            try:
                subprocess.run(["git", "apply", patch_path], check=True, capture_output=True)
            except subprocess.CalledProcessError as error:
                print("Could not apply patch... \n\n%s" % error.stderr.decode())


def main():
    """
    Program Entry Point
    """
    data = __read_json(os.path.join(os.path.abspath(RELATIVE_VENDOR_FOLDER_LOCATION),
                                    'patches.json'))
    for repo in data['repositories']:
        vendor = Vendor(repo['name'], repo['filePath'], repo['patches'],
                        os.path.abspath(RELATIVE_VENDOR_FOLDER_LOCATION))
        vendor.apply_patches()


if __name__ == '__main__':
    # git apply --numstat -z ...
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    main()
