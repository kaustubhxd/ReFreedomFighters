"""specs_s37105.py - cascade s6 batch 37105 (0x427c10, thiscall(path) ret 4). IAT slots: strchr 0x676254 / strrchr 0x676258 (real behaviour, cdecl), CreateDirectory 0x6760d4,
GetLastError 0x67609c, FormatMessage 0x6760ec (writes a deterministic text into its buffer). All stubs and the object's slots 0x34 / 0x4c / logger slot 0x2c log the C strings they
receive (the buffers are on the stack, so addresses are never recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _cs(em, a):
    out = bytearray()
    while len(out) < 0x400:
        b = em.rbytes(a + len(out), 1)[0]
        if b == 0:
            break
        out.append(b)
    return bytes(out)


def _g427c10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mk_find(name, last):
        def h(em, res_):
            s = em.arg32(0)
            ch = em.arg32(1) & 0xff
            data = _cs(em, s)
            i = data.rfind(bytes([ch])) if last else data.find(bytes([ch]))
            em.ret(eax=(s + i) if i >= 0 else 0, argbytes=0)
        return e.stub_fn(name, h)
    e.w32(0x676254, mk_find('strchr', False))
    e.w32(0x676258, mk_find('strrchr', True))
    created = r.random() < 0.5

    def mkdir(em, res_):
        em.calllog.append(('mkdir', _cs(em, em.arg32(0)), em.arg32(1)))
        em.ret(eax=1 if created else 0, argbytes=8)
    e.w32(0x6760d4, e.stub_fn('CreateDirectory', mkdir))
    e.w32(0x67609c, pystub(c, 0, ret=lambda em, k: r.getrandbits(32)))

    def fmt(em, res_):
        em.calllog.append(('fmsg', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(5), em.arg32(6)))
        em.wbytes(em.arg32(4), b'E' + (em.arg32(2) & 0xffff).to_bytes(2, 'little') + b'\x00')
        em.ret(eax=3, argbytes=28)
    e.w32(0x6760ec, e.stub_fn('FormatMessage', fmt))

    def lg(em, res_):
        n = 3 if em.arg32(1) == 0x678c50 else 4
        em.calllog.append(('log', em.arg32(1), tuple(_cs(em, em.arg32(i)) for i in range(2, n))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    have = r.random() < 0.3

    def s34(em, res_):
        em.calllog.append(('has', _cs(em, em.arg32(0)), em.arg32(1)))
        em.ret(eax=0x100 if have else 0x101 if r.random() < 0.1 else 0, argbytes=8)

    def s4c(em, res_):
        em.calllog.append(('parent', _cs(em, em.arg32(0))))
        em.ret(eax=0, argbytes=4)
    me = obj(c, 0x20, {0x34: e.stub_fn('s34', s34), 0x4c: e.stub_fn('s4c', s4c)})
    mode = r.random()
    if mode < 0.08:
        n = r.choice([0x102, 0x103, 0x105, 0x106])
        txt = bytes(r.choice(b'ab/\\') for _ in range(n))
    else:
        n = r.choice([0, 1, 3, 6, 12, 20])
        txt = bytes(r.choice(b'ab/\\.c') for _ in range(n))
    a = e.alloc(len(txt) + 0x20, 4)
    e.wbytes(a, txt + b'\x00' + bytes(r.randrange(1, 255) for _ in range(0x1f)))
    return [me, a]


S(0x427c10, 'GUESS make_directories', 'thiscall', None, ret=None, gen=_g427c10, note='batch37105')
