"""specs_s38078.py - cascade s8 batch 38078. thiscall(arg) ret 4. this+0x15 (unaligned) = file object whose slots are Python stubs driven by a pre-generated record list: eof (0x1c; first call sometimes 1, then 1 once all
records were consumed), tell (0xc, counter), seek (0x10), read (0x14: n == 4 -> next signature, n == 0x2a -> next entry with name / extra / comment lengths, otherwise name or filler bytes). Signatures: 0x2014b50 mostly, the two
terminators and an unknown value (error 0x5a6 + assert). Names start with the _strnicmp prefix half of the time. 0x4d6520 / 0x4d7170 are custom hooks logging the structures by content; _strnicmp (IAT 0x67640c) is a logging
stub; this / arg have slot 0x54 (logs the name text). Logger and assert hook always set."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _cstr(em, p, lim=0x100):
    out = b''
    while len(out) < lim:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g4d6e80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    prefix = bytes(e.rbytes(0x696b24, 5))

    def printer(em, res_):
        a1 = em.arg32(1)
        row = ('log', em.arg32(0) != 0, a1)
        if a1 == 0x696b30:
            row += (_cstr(em, em.arg32(2)), em.arg32(3), em.arg32(4))
        em.calllog.append(row)
        em.ret(eax=0)
    st = obj(c, 0x20, {0x2c: e.stub_fn('printer', printer)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    nrec = r.choice([0, 1, 2, 3, 4])
    recs = []
    for i in range(nrec):
        k = r.random()
        sig = 0x2014b50 if k < 0.75 else r.choice([0x6054b50, 0x52756e65, 0x12345678])
        nl = r.choice([0, 3, 7, 12, 40])
        nm = (r.choice([prefix, prefix, prefix[:4] + b'~']) if r.random() < 0.6 else b'') + bytes(r.choice(b'abcXYZ_/.019') for _ in range(max(nl - 5, 0) if nl else 0))
        nm = nm[:nl] if nl else b''
        ent = bytearray(r.randbytes(0x2a))
        ent[0x18:0x1a] = struct.pack('<H', len(nm))
        ent[0x1a:0x1c] = struct.pack('<H', r.choice([0, 0, 5]))
        ent[0x1c:0x1e] = struct.pack('<H', r.choice([0, 0, 9]))
        recs.append((sig, bytes(ent), nm))
    st_ = {'sig': 0, 'ent': 0, 'name': 0, 'eof': 0, 'nextname': b''}
    first_eof = r.random() < 0.1

    def eof(em, res_):
        em.calllog.append(('eof',))
        st_['eof'] += 1
        v = 1 if (first_eof and st_['eof'] == 1) or st_['sig'] >= len(recs) else 0
        em.ret(eax=v, argbytes=4)

    def tell(em, res_):
        em.calllog.append(('tell', em.arg32(0)))
        em.ret(eax=0x100 * (len(em.calllog) % 7), argbytes=4)

    def seek(em, res_):
        em.calllog.append(('seek', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)

    def read(em, res_):
        buf, n, h = em.arg32(0), em.arg32(1), em.arg32(2)
        if n == 4 and st_['sig'] < len(recs):
            sig, ent, nm = recs[st_['sig']]
            st_['sig'] += 1
            st_['cur'] = (ent, nm)
            data = struct.pack('<I', sig)
        elif n == 0x2a and 'cur' in st_:
            data = st_['cur'][0]
        elif 'cur' in st_ and n == len(st_['cur'][1]):
            data = st_['cur'][1]
        else:
            data = bytes(r.getrandbits(8) for _ in range(n))
        em.calllog.append(('read', n, h, data[:0x2a]))
        em.wbytes(buf, data)
        em.ret(eax=n, argbytes=12)
    F = obj(c, 0x40, {0x1c: e.stub_fn('eof', eof), 0xc: e.stub_fn('tell', tell), 0x10: e.stub_fn('seek', seek), 0x14: e.stub_fn('read', read)})

    def s54(name):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx') != 0, _cstr(em, em.arg32(0))))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn(name, h)
    this = obj(c, 0x40, {0x54: s54('this54')})
    arg = obj(c, 0x40, {0x54: s54('arg54')})
    for o in (this, arg):
        e.wbytes(o + 0xd, struct.pack('<I', r.getrandbits(32)))
    e.wbytes(this + 0x15, struct.pack('<I', F))
    e.wbytes(arg + 0x11, struct.pack('<I', r.getrandbits(32)))
    e.wbytes(arg + 0x2e, struct.pack('<I', r.getrandbits(16)))

    def a6520(em, res_):
        name = _cstr(em, em.arg32(0))
        v = r.choice([0, 1, 1, 1])
        em.calllog.append(('4d6520', em.reg('ecx') != 0, name, em.arg32(2), v))
        if v:
            em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0x1c)))
        em.ret(eax=v, argbytes=12)
    e.hook(0x4d6520, a6520)

    def a7170(em, res_):
        cx, ar = em.reg('ecx'), em.arg32(0)
        em.calllog.append(('4d7170', bytes(em.rbytes(cx, 0x1c)), bytes(em.rbytes(ar, 0x1c))))
        em.ret(eax=r.choice([0, 1]), argbytes=4)
    e.hook(0x4d7170, a7170)

    def sni(em, res_):
        n = em.arg32(2)
        a, b = _cstr(em, em.arg32(0), n), _cstr(em, em.arg32(1), n)
        em.calllog.append(('strnicmp', a, b, n))
        em.ret(eax=0 if a.lower() == b.lower() else 1, argbytes=0)
    e.w32(0x67640c, e.stub_fn('_strnicmp', sni))
    return [this, arg]


S(0x4d6e80, 'GUESS zip directory reader', 'thiscall', None, ret=None, gen=_g4d6e80, note='batch38078')
