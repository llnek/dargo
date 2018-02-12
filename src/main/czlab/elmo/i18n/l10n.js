// This library is distributed in  the hope that it will be useful but without
// any  warranty; without  even  the  implied  warranty of  merchantability or
// fitness for a particular purpose.
// The use and distribution terms for this software are covered by the Eclipse
// Public License 1.0  (http://opensource.org/licenses/eclipse-1.0.php)  which
// can be found in the file epl-v10.html at the root of this distribution.
// By using this software in any  fashion, you are agreeing to be bound by the
// terms of this license. You  must not remove this notice, or any other, from
// this software.
// Copyright (c) 2013-2015, Ken Leung. All rights reserved.

"use strict";/**
 * @requires zotohlab/asx/asterix
 * @module i18n/l10n
 */

import sh from 'zotohlab/asx/asterix';


let sjs= sh.skarojs,
xcfg = sh.xcfg,
undef;

/** @alias module:i18n/l10n */
const xbox = sjs.merge(xcfg.l10nTable, {

  "en" : {

    "%whosturn" : "{{who}}'s TURN...",
    "%whodraw" : "Draw!",
    "%whowin" : "{{who}} Wins!",
    "%computer" : 'Computer',
    "%player2" : 'Player 2',
    "%player1" : 'Player 1',

    "%quit!" : 'Quit',
    "%back" : 'Back',
    "%ok" : 'OK',

    "%cpu" : "CPU",
    "%p2" : "P2",
    "%p1" : "P1",

    "%mmenu" : 'Main Menu',

    "%replay" : 'REPLAY',
    "%play" : 'PLAY',

    "%quit?" : 'Continue to quit game?',
    "%scores" : '= scores ='


  }

});




sjs.merge(exports, xbox);
/*@@
return xbox;
@@*/
//////////////////////////////////////////////////////////////////////////////
//EOF

