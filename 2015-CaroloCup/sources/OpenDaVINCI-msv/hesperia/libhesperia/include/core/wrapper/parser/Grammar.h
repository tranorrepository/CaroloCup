/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_WRAPPER_PARSER_GRAMMAR_H_
#define HESPERIA_CORE_WRAPPER_PARSER_GRAMMAR_H_

#include <string>
#include <vector>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "core/wrapper/parser/ASTNode.h"
#include "core/wrapper/parser/ParserTokenListener.h"
#include "core/wrapper/parser/ParserTokenExtendedData.h"
#include "core/wrapper/parser/ParserErrorListener.h"
#include "core/wrapper/parser/ParserErrorExtendedData.h"

namespace core {
    namespace wrapper {
        namespace parser {

            using namespace std;

            /**
             * This class represents a grammar.
             */
            class OPENDAVINCI_API Grammar  {
                public:
                    /**
                     * Constructor.
                     *
                     * @param ptl Token listener for this grammar.
                     * @param pel Error listener for this grammar.
                     */
                    Grammar(ParserTokenListener &ptl, ParserErrorListener &pel);

                    /**
                     * Copy constructor.
                     *
                     * @param obj Other object.
                     */
                    Grammar(const Grammar &obj);

                    /**
                     * Assignment operator.
                     *
                     * @param obj Other object.
                     * @return Reference to this object.
                     */
                    Grammar& operator=(const Grammar &obj);

                    virtual ~Grammar();

                    /**
                     * This method parses the given input.
                     *
                     * @param s Input to be parsed.
                     */
                    virtual ASTNode* getAST(const string &s) = 0;

                    /**
                     * This method returns the grammar error listener.
                     *
                     * @return Grammar error listener.
                     */
                    ParserTokenListener& getGrammarTokenListener() const;

                    /**
                     * This method returns the grammar error listener.
                     *
                     * @return Grammar error listener.
                     */
                    ParserErrorListener& getGrammarErrorListener() const;

                    /**
                     * This method tracks the life cycle of token's extended data.
                     *
                     * @param gted Token's extended data.
                     */
                    void add(ParserTokenExtendedData *gted);

                    /**
                     * This method tracks the life cycle of parser error's extended data.
                     *
                     * @param gpeed Parser error's extended data.
                     */
                    void add(ParserErrorExtendedData *gpeed);

                    /**
                     * This method increments the number of processed lines.
                     */
                    void incrementLines();

                    /**
                     * This method reset the number of processed lines.
                     */
                    void resetLines();

                    /**
                     * This method returns the currently processed line.
                     *
                     * @return The currently processed line.
                     */
                    uint32_t getCurrentLine() const;

                private:
                    ParserTokenListener &m_tokenListener;
                    ParserErrorListener &m_errorListener;
                    vector<ParserTokenExtendedData*> m_listOfParserTokenExtendedData;
                    vector<ParserErrorExtendedData*> m_listOfGrammarParserErrorExtendedData;
                    uint32_t m_lines;
            };

        }
    }
} // core::wrapper::parser

#endif /*HESPERIA_CORE_WRAPPER_PARSER_GRAMMAR_H_*/
