// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testFileFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:56:44
// Description: Provides 100% unit test coverage over all file utility functions

#include <gtest/gtest.h>
#include "../../include/internal/Files/textFile.hpp"
#include "../../include/internal/Files/markupFile.hpp"

using namespace Utilities_API::Files;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testFileFunctions, testForFileNameFunctionality)
{
    FileNamePtr fullFileName {std::make_shared<FileName>("../../include/internal/Files/fileComponents.hpp")};

    ASSERT_EQ("../../include/internal/Files", fullFileName->getRelativePathToFile());
    ASSERT_EQ("../../include/internal/Files/fileComponents.hpp", fullFileName->getFullFileName());
    ASSERT_EQ("fileComponents.hpp", fullFileName->getBaseFileName());
    ASSERT_EQ("hpp", fullFileName->getFileExtension());


    FileNamePtr fileName {std::make_shared<FileName>("testFileFunctions.cpp")};

    ASSERT_EQ("", fileName->getRelativePathToFile());
    ASSERT_EQ("testFileFunctions.cpp", fileName->getFullFileName());
    ASSERT_EQ("testFileFunctions.cpp", fileName->getBaseFileName());
    ASSERT_EQ("cpp", fileName->getFileExtension());
}

TEST(testFileFunctions, testForFileContentsFunctionality)
{
    std::vector<std::string> contentsOfFile
        { "# This is a test file for use in testing the functionality of the file utility functions",
          "# Default comments are denoted using a '#' symbol",
          "// Other comments can be specified by the symbol used",
          "Plain text is written without the hash" };


    FileNamePtr fileName { std::make_shared<FileName>("test.txt") };
    FileContentsPtr fileContents {std::make_shared<FileContents>(fileName)};

    ASSERT_EQ(contentsOfFile, fileContents->getContentInFile());


    FileNamePtr fileNameWithPath { std::make_shared<FileName>("../TestFiles/test.txt") };
    FileContentsPtr fileContentsWithPath {std::make_shared<FileContents>(fileNameWithPath)};

    ASSERT_EQ(contentsOfFile, fileContentsWithPath->getContentInFile());
}

TEST(testFileFunctions, testForTextFileFunctionality)
{
    std::vector<std::string> line1 { {"#"}, {"This"}, {"is"}, {"a"}, {"test"}, {"file"}, {"for"},
                                     {"use"}, {"in"}, {"testing"}, {"the"}, {"functionality"},
                                     {"of"},  {"the"}, {"file"}, {"utility"}, {"functions"} };

    std::vector<std::string> line2 { {"#"}, {"Default"}, {"comments"}, {"are"}, {"denoted"},
                                     {"using"}, {"a"}, {"'#'"}, {"symbol"} };

    std::vector<std::string> line3 { {"//"}, {"Other"}, {"comments"}, {"can"}, {"be"},
                                     {"specified"}, {"by"}, {"the"}, {"symbol"}, {"used"} };

    std::vector<std::string> line4 { {"Plain"}, {"text"}, {"is"}, {"written"}, {"without"}, {"the"},
                                     {"hash"} };


    // Use of all defaults
    InputFilePtr defaultsTextFile {std::make_shared<TextFile>("test.txt")};

    std::vector< std::vector<std::string> > defaultDataResults { line3, line4 };
    std::vector< std::vector<std::string> > defaultMetaDataResults { line1, line2 };

    ASSERT_EQ(defaultDataResults, defaultsTextFile->getSuperDataVector());
    ASSERT_EQ(defaultMetaDataResults, defaultsTextFile->getSuperMetaDataVector());


    // Use of a different comment style
    InputFilePtr c_styleCommentsTextFile {std::make_shared<TextFile>("test.txt", "//")};

    std::vector< std::vector<std::string> > c_styleDataResults { line1, line2, line4 };
    std::vector< std::vector<std::string> > c_styleMetaDataResults { line3 };

    ASSERT_EQ(c_styleDataResults, c_styleCommentsTextFile->getSuperDataVector());
    ASSERT_EQ(c_styleMetaDataResults, c_styleCommentsTextFile->getSuperMetaDataVector());


    // Use of a selection vector
    std::vector<std::string> seletionVector {"comments"};
    InputFilePtr selectMetaTextFile {std::make_shared<TextFile>("test.txt", "#", seletionVector)};

    std::vector< std::vector<std::string> > selectDataResults { line3, line4 };
    std::vector< std::vector<std::string> > selectMetaDataResults { line2 };

    ASSERT_EQ(selectDataResults, selectMetaTextFile->getSuperDataVector());
    ASSERT_EQ(selectMetaDataResults, selectMetaTextFile->getSuperMetaDataVector());
}

TEST(testFileFunctions, testForMarkupFileFunctionality)
{
    std::vector<std::string> dataTag { {"This"}, {"is"}, {"the"}, {"data"}, {"within"}, {"the"},
                                       {"data"}, {"tag"} };

    std::vector<std::string> metadataTag { {"This"}, {"is"}, {"the"}, {"data"}, {"within"}, {"the"},
                                           {"metadata"}, {"tag"} };

    std::vector<std::string> otherdataTag { {"This"}, {"is"}, {"the"}, {"data"}, {"within"},
                                            {"some"}, {"other,"}, {"non-default"}, {"tag"} };


    // Using the default tag values
    InputFilePtr defaultTagFile {std::make_shared<MarkupFile>("test.inp")};

    std::vector< std::vector<std::string> > defaultTagDataResults { dataTag };
    std::vector< std::vector<std::string> > defaultTagMetaDataResults { metadataTag };

    ASSERT_EQ(defaultTagDataResults, defaultTagFile->getSuperDataVector());
    ASSERT_EQ(defaultTagMetaDataResults, defaultTagFile->getSuperMetaDataVector());


    // Using otherTag for data
    InputFilePtr otherDataTagFile {std::make_shared<MarkupFile>("test.inp", "<otherTag>")};

    std::vector< std::vector<std::string> > otherDataTagDataResults { otherdataTag };
    std::vector< std::vector<std::string> > otherDataTagMetaDataResults { metadataTag };

    ASSERT_EQ(otherDataTagDataResults, otherDataTagFile->getSuperDataVector());
    ASSERT_EQ(otherDataTagMetaDataResults, otherDataTagFile->getSuperMetaDataVector());


    // Using otherTag for metadata
    InputFilePtr otherMetaDataTagFile {std::make_shared<MarkupFile>("test.inp", "<data>", "<otherTag>")};

    std::vector< std::vector<std::string> > otherMetaDataTagDataResults { dataTag };
    std::vector< std::vector<std::string> > otherMetaDataTagMetaDataResults { otherdataTag };

    ASSERT_EQ(otherMetaDataTagDataResults, otherMetaDataTagFile->getSuperDataVector());
    ASSERT_EQ(otherMetaDataTagMetaDataResults, otherMetaDataTagFile->getSuperMetaDataVector());
}
