"""specs_s907.py - gap-band slice, batch 907: 0x41e120 (GUESS name Log41e120), cdecl, varargs (format, two words), no result.
Stand-ins: the USER32 import wvsprintfA (stub_import; stdcall, three words; writes "out:" + the format text and logs the format and the
two words it reads through the argument pointer), and 0x42ab49 (cdecl, three words: logs the handle, the format and the buffer text).
The handle global 0x6fd1a4 is set per case. The exe's stack cookie check is not reproduced."""
from pilot import S
from anim_common import only_hooks


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    fmt = e.cstr('v=%d %d %s')
    fmt_txt = 'v=%d %d %s'

    def wvsp(e, rr):
        buf, f, va = e.arg32(0), e.arg32(1), e.arg32(2)
        txt = 'out:' + ''.join(chr(b) for b in e.rbytes(f, 12) if 32 <= b < 127)
        e.wbytes(buf, txt.encode('latin-1') + b'\0')
        e.calllog.append(('wvsprintf', txt, e.r32(va), e.r32(va + 4)))
        e.ret(eax=len(txt), argbytes=12)

    def logger(e, rr):
        h, f, b = e.arg32(0), e.arg32(1), e.arg32(2)
        s = e.rbytes(b, 40).split(b'\0')[0]
        e.calllog.append(('42ab49', h, e.rbytes(f, 10).split(b'\0')[0], s))
        e.ret(eax=0, argbytes=0)

    e.stub_import('wvsprintfA', wvsp)
    only_hooks(c, {0x42ab49: logger})
    e.w32(0x6fd1a4, r.getrandbits(32))
    w1, w2 = r.getrandbits(32), r.getrandbits(32)
    return [fmt, w1, w2]


S(0x41e120, 'Log41e120 (GUESS name; varargs)', 'cdecl', None, gen=_gen, note='area50 batch907 (band slice)')
