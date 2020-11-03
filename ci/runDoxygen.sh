#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: runDoxygen.sh - Version 1.0.0
# Author: crdrisko
# Date: 10/07/2020-07:20:58
# Description: Run doxygen on the gh-pages branch updating the website

set -e

git clone -b gh-pages https://github.com/crdrisko/cpp-units.git docs_build
cd docs_build || exit 1

git config --global push.default simple
git config user.name "Travis CI"
git config user.email "travis@travis-ci.org"

# go back to first commit
git reset --hard "$( git rev-list --max-parents=0 --abbrev-commit HEAD )"

doxygen "$TRAVIS_BUILD_DIR/docs/Doxyfile" 2>&1 | tee doxygen.log

[[ ! -d "html" || ! -f "html/index.html" ]] && exit 1

echo "Adding..." && git add --all
echo "Commiting..." && git commit -m "Deploy code docs to GitHub Pages Travis build: ${TRAVIS_BUILD_NUMBER}"
echo "Pushing..." && git push --force https://github.com/crdrisko/cpp-units.git > /dev/null 2>&1
