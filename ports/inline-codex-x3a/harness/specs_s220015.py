"""Focused fixture for 0x62c860's bounded character-to-UTF-8 loop."""
from pilot import S
from recruits_util import clear_hooks, pystub, rnd


def g62c860(c):
    """Exercise table bytes, callback conversion widths, and output exhaustion.

    Arguments are (table, source_cursor_ptr, source_end, output_cursor_ptr,
    output_end).  The table's +0x378 entries are a signed output-byte count;
    a zero count dispatches through (+0x170, +0x174) and emits UTF-8 into the
    original routine's four-byte stack scratch area.
    """
    clear_hooks(c)
    e, r = c.emu, c.rng
    mode = c.case % 8
    table = rnd(c, 0x800)
    source = rnd(c, 8)
    source_cursor = rnd(c, 4)
    output = rnd(c, 32)
    output_cursor = rnd(c, 4)

    # Direct-table cases cover one, two, and three byte entries in one loop.
    # The short-output case must preserve the next source byte and cursor.
    if mode == 7:
        # Empty input is a distinct early-return path: the routine must not
        # dereference the byte parked just beyond source_end.
        text = b''
        e.w8(source, 0x41)
        base = table + 0x378 + 0x41 * 4
        e.w8(base, 1)
        e.w8(base + 1, ord('!'))
        cp = 0x24
        capacity = 16
    elif mode in (0, 1):
        text = bytes((0x41, 0x42, 0x43))
        e.wbytes(source, text)
        entries = ((0x41, b'A'), (0x42, b'xy'), (0x43, b'123'))
        for ch, payload in entries:
            base = table + 0x378 + ch * 4
            e.w8(base, len(payload))
            e.wbytes(base + 1, payload)
        cp = 0x24
        capacity = 16 if mode == 0 else 2
    else:
        # A fallback entry advances one source byte when table[0x4c + ch] is
        # four.  Use all legal UTF-8 widths, plus an insufficient 4-byte dst.
        ch = 0x80 + mode
        text = bytes((ch,))
        e.wbytes(source, text)
        e.w8(table + 0x378 + ch * 4, 0)
        e.w8(table + 0x4c + ch, 4)
        cp = {2: 0x24, 3: 0x7ff, 4: 0x800, 5: 0x10000, 6: 0x10000}[mode]
        capacity = 16 if mode != 6 else 3

    # The real callback is cdecl(ctx, source_ptr); recording it makes the
    # indirect call and both arguments observable in addition to the result.
    callback = pystub(c, 2, ret=cp, pop=0)
    e.w32(table + 0x170, callback)
    e.w32(table + 0x174, 0x13570000 | mode)
    e.w32(source_cursor, source)
    e.w32(output_cursor, output)
    return [table, source_cursor, source + len(text), output_cursor, output + capacity]


S(0x62c860, 'table/callback character conversion to UTF-8', 'cdecl', None,
  ret='eax', gen=g62c860, note='batch220015 focused table + UTF-8 fixture')
