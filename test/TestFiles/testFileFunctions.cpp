// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testFileFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:56:44
// Description: Provides ~100% unit test coverage over all file utility functions

#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../../include/common-utils/files.hpp"

using namespace CommonUtilities::Files;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

GTEST_TEST(testFileFunctions, fileNameWithFullPathIsParsedCorrectly)
{
    FileName fullFileName {"../../include/common-utils/internal/Files/fileComponents.hpp"};

    ASSERT_EQ("../../include/common-utils/internal/Files/fileComponents.hpp", fullFileName.getFullFileName());
    ASSERT_EQ("../../include/common-utils/internal/Files", fullFileName.getRelativePathToFile());
    ASSERT_EQ("fileComponents.hpp", fullFileName.getBaseFileName());
    ASSERT_EQ("hpp", fullFileName.getFileExtension());
}

GTEST_TEST(testFileFunctions, fileNameWithNoPathIsParsedCorrectly)
{
    FileName fileName {"testFileFunctions.cpp"};

    ASSERT_EQ("", fileName.getRelativePathToFile());
    ASSERT_EQ("testFileFunctions.cpp", fileName.getFullFileName());
    ASSERT_EQ("testFileFunctions.cpp", fileName.getBaseFileName());
    ASSERT_EQ("cpp", fileName.getFileExtension());
}

GTEST_TEST(testFileFunctions, fileContentParsingFunctionsCorrectlyRegardlessOfFileName)
{
    std::vector<std::string> contentsOfFile
    {
        "# This is a test file for use in testing the functionality of the file utility functions",
        "# Default comments are denoted using a '#' symbol",
        "// Other comments can be specified by the symbol used",
        "Plain text is written without the hash"
    };


    FileName fileName {"test.txt"};
    FileContents fileContents {fileName};

    ASSERT_EQ(contentsOfFile, fileContents.getContentInFile());


    FileName fileNameWithPath {"../TestFiles/test.txt"};
    FileContents fileContentsWithPath {fileNameWithPath};

    ASSERT_EQ(contentsOfFile, fileContentsWithPath.getContentInFile());
}

GTEST_TEST(testFileFunctions, filesThatDontExistThrowFatalExceptions)
{
    ASSERT_DEATH(
    {
        FileName fileNameThatDoesntExist {"test2.txt"};
        FileContents fileContents {fileNameThatDoesntExist};
    }, "Common-Utilities Fatal Error:\n\tUnable to open file: test2.txt\n");


    ASSERT_DEATH(
    {
        InputFilePtr defaultsTextFile { std::make_shared<TextFile>("test2.txt") };
    }, "Common-Utilities Fatal Error:\n\tUnable to open file: test2.txt\n");


    ASSERT_DEATH(
    {
        InputFilePtr defaultsTextFile { std::make_shared<MarkupFile>("test2.inp") };
    }, "Common-Utilities Fatal Error:\n\tUnable to open file: test2.inp\n");
}

GTEST_TEST(testFileFunctions, textFileOpensAndReadsSampleFileCorrectly)
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
    InputFilePtr defaultsTextFile { std::make_shared<TextFile>("test.txt") };

    std::vector< std::vector<std::string> > defaultDataResults { line3, line4 };
    std::vector< std::vector<std::string> > defaultMetaDataResults { line1, line2 };

    ASSERT_EQ(defaultDataResults, defaultsTextFile->getSuperDataVector());
    ASSERT_EQ(defaultMetaDataResults, defaultsTextFile->getSuperMetaDataVector());


    // Use of a different comment style
    InputFilePtr c_styleCommentsTextFile { std::make_shared<TextFile>("test.txt", "//") };

    std::vector< std::vector<std::string> > c_styleDataResults { line1, line2, line4 };
    std::vector< std::vector<std::string> > c_styleMetaDataResults { line3 };

    ASSERT_EQ(c_styleDataResults, c_styleCommentsTextFile->getSuperDataVector());
    ASSERT_EQ(c_styleMetaDataResults, c_styleCommentsTextFile->getSuperMetaDataVector());


    // Use of a selection vector
    std::vector<std::string> seletionVector {"comments"};
    InputFilePtr selectMetaTextFile { std::make_shared<TextFile>("test.txt", "#", seletionVector) };

    std::vector< std::vector<std::string> > selectDataResults { line3, line4 };
    std::vector< std::vector<std::string> > selectMetaDataResults { line2 };

    ASSERT_EQ(selectDataResults, selectMetaTextFile->getSuperDataVector());
    ASSERT_EQ(selectMetaDataResults, selectMetaTextFile->getSuperMetaDataVector());
}

GTEST_TEST(testFileFunctions, markupFileOpensAndReadsSampleFileCorrectly)
{
    std::vector<std::string> dataTag { {"This"}, {"is"}, {"the"}, {"data"}, {"within"}, {"the"},
                                       {"data"}, {"tag"} };

    std::vector<std::string> metadataTag { {"This"}, {"is"}, {"the"}, {"data"}, {"within"}, {"the"},
                                           {"metadata"}, {"tag"} };

    std::vector<std::string> otherdataTag { {"This"}, {"is"}, {"the"}, {"data"}, {"within"},
                                            {"some"}, {"other,"}, {"non-default"}, {"tag"} };


    // Using the default tag values
    InputFilePtr defaultTagFile { std::make_shared<MarkupFile>("test.inp") };

    std::vector< std::vector<std::string> > defaultTagDataResults { dataTag };
    std::vector< std::vector<std::string> > defaultTagMetaDataResults { metadataTag };

    ASSERT_EQ(defaultTagDataResults, defaultTagFile->getSuperDataVector());
    ASSERT_EQ(defaultTagMetaDataResults, defaultTagFile->getSuperMetaDataVector());


    // Using otherTag for data
    InputFilePtr otherDataTagFile { std::make_shared<MarkupFile>("test.inp", "<otherTag>") };

    std::vector< std::vector<std::string> > otherDataTagDataResults { otherdataTag };
    std::vector< std::vector<std::string> > otherDataTagMetaDataResults { metadataTag };

    ASSERT_EQ(otherDataTagDataResults, otherDataTagFile->getSuperDataVector());
    ASSERT_EQ(otherDataTagMetaDataResults, otherDataTagFile->getSuperMetaDataVector());


    // Using otherTag for metadata
    InputFilePtr otherMetaDataTagFile { std::make_shared<MarkupFile>("test.inp", "<data>", "<otherTag>") };

    std::vector< std::vector<std::string> > otherMetaDataTagDataResults { dataTag };
    std::vector< std::vector<std::string> > otherMetaDataTagMetaDataResults { otherdataTag };

    ASSERT_EQ(otherMetaDataTagDataResults, otherMetaDataTagFile->getSuperDataVector());
    ASSERT_EQ(otherMetaDataTagMetaDataResults, otherMetaDataTagFile->getSuperMetaDataVector());
}
